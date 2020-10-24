// Contains a futures queue that has a maximum size with its
// given requests

// Create a request queue per instrument + engine instance
// limit the amount of messages recieved to .e.
// all write requests are added to queue
// services that implement write functionality will do so
// through the given queue and 
// A single queue is instantiated per instrument

// Push Queue
// ------------------------------------------>
// adds a given event with its promise to the
// queue.

// Push snapshot

// Insert Batch

// Inject Queue 
// ------------------------------------------>
// allows for priority events to be inserted 
// in-front of other events.

// Pop Queue
// ------------------------------------------>
// removes a given batch from the queue to be 
// processed with responses to their respective
// events

// Req Batch

class Queue {

    };

#pragma once

/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <atomic>
#include <chrono>
#include <deque>
#include <future>
#include <memory>
#include <mutex>
#include <optional>
#include <stdexcept>
#include <thread>

#include <ATen/core/ivalue.h>
#include <torch/script.h>

#include <boost/log/trivial.hpp>
#include "types.h"
#include "nest.h"
#include <doctest.h>

// Batching Queue
// ---------------------------------------------------------------------------------->

TensorNest batch(const std::vector<TensorNest>& tensors, int64_t batch_dim) {
  // TODO(heiner): Consider using accessors and writing slices ourselves.
  try{
    nest::Nest<std::vector<torch::Tensor>> zipped = TensorNest::zip(tensors);
    return zipped.map([batch_dim](const std::vector<torch::Tensor>& v) {
      return torch::cat(v, batch_dim);
    });
  } catch (std::exception& e) {
    BOOST_LOG_TRIVIAL(error) << "Error in batch:" << e.what();  
    throw e;
  }
}

struct ClosedBatchingQueue : public std::runtime_error {
 public:
  using std::runtime_error::runtime_error;
};

struct Empty {};

template <typename T = Empty>
class BatchingQueue {
 public:
  struct QueueItem {
    TensorNest tensors;
    T payload;
  };
  BatchingQueue(int64_t batch_dim, int64_t minimum_batch_size,
                int64_t maximum_batch_size,
                std::optional<int> timeout_ms = std::nullopt,
                bool check_inputs = true,
                std::optional<uint64_t> maximum_queue_size = std::nullopt)
      : batch_dim_(batch_dim),
        minimum_batch_size_(
            minimum_batch_size > 0
                ? minimum_batch_size
                : throw std::invalid_argument("Min batch size must be >= 1")),
        maximum_batch_size_(
            maximum_batch_size >= minimum_batch_size
                ? maximum_batch_size
                : throw std::invalid_argument("Max batch size must be >= min batch size")),
        timeout_(timeout_ms),
        maximum_queue_size_(maximum_queue_size),
        check_inputs_(check_inputs) {
    if (maximum_queue_size_ != std::nullopt &&
        *maximum_queue_size_ < maximum_batch_size_) {
      throw std::invalid_argument("Max queue size must be >= max batch size");
    }
  }

  int64_t size() const {
    std::unique_lock<std::mutex> lock(mu_);
    return deque_.size();
  }

  void enqueue(QueueItem item) {
    if (check_inputs_) {
      bool is_empty = true;

      try{
        item.tensors.for_each([this, &is_empty](const torch::Tensor& tensor) {
          is_empty = false;

          if (tensor.dim() <= batch_dim_) {
            throw std::invalid_argument(
                "Enqueued tensors must have more than batch_dim == " +
                std::to_string(batch_dim_) + " dimensions, but got " +
                std::to_string(tensor.dim()));
          }
        });
      } catch (std::exception& e) {
        BOOST_LOG_TRIVIAL(error) << "Error in enqueue:" << e.what();  
        throw e;
      }

      if (is_empty) {
        throw std::invalid_argument("Cannot enqueue empty vector of tensors");
      }
    }

    bool should_notify = false;
    {
      std::unique_lock<std::mutex> lock(mu_);
      // Block when maximum_queue_size is reached.
      while (maximum_queue_size_ != std::nullopt && !is_closed_ &&
             deque_.size() >= *maximum_queue_size_) {
        can_enqueue_.wait(lock);
      }
      if (is_closed_) {
        throw ClosedBatchingQueue("Enqueue to closed queue");
      }
      deque_.push_back(std::move(item));
      should_notify = deque_.size() >= minimum_batch_size_;
    }

    if (should_notify) {
      enough_inputs_.notify_one();
    }
  }

  std::pair<TensorNest, std::vector<T>> dequeue_many() {
    std::vector<TensorNest> tensors;
    std::vector<T> payloads;
    {
      std::unique_lock<std::mutex> lock(mu_);

      bool timed_out = false;
      while (!is_closed_ &&
             (deque_.empty() ||
              (!timed_out && deque_.size() < minimum_batch_size_))) {
        if (timeout_ == std::nullopt) {
          // If timeout_ isn't set, stop waiting when:
          // - queue is closed, or
          // - we have enough inputs inside the queue.
          enough_inputs_.wait(lock);
        } else {
          // If timeout_ is set, stop waiting when:
          // - queue is closed, or
          // - we timed out and have at least one input, or
          // - we have enough inputs in the queue.
          timed_out = (enough_inputs_.wait_for(lock, *timeout_) ==
                       std::cv_status::timeout);
        }
      }

      if (is_closed_) {
        throw std::invalid_argument("Queue is closed");
      }
      const int64_t batch_size =
          std::min<int64_t>(deque_.size(), maximum_batch_size_);
      for (auto it = deque_.begin(), end = deque_.begin() + batch_size;
           it != end; ++it) {
        tensors.push_back(std::move(it->tensors));
        payloads.push_back(std::move(it->payload));
      }
      deque_.erase(deque_.begin(), deque_.begin() + batch_size);
    }
    can_enqueue_.notify_all();
    return std::make_pair(batch(tensors, batch_dim_), std::move(payloads));
  }

  bool is_closed() const {
    std::unique_lock<std::mutex> lock(mu_);
    return is_closed_;
  }

  void close() {
    {
      std::unique_lock<std::mutex> lock(mu_);
      if (is_closed_) {
        throw std::invalid_argument("Queue was closed already");
      }
      is_closed_ = true;
      deque_.clear();
    }
    enough_inputs_.notify_all();  // Wake up dequeues.
    can_enqueue_.notify_all();
  }

 private:
  mutable std::mutex mu_;

  const int64_t batch_dim_;
  const uint64_t minimum_batch_size_;
  const uint64_t maximum_batch_size_;
  const std::optional<std::chrono::milliseconds> timeout_;
  const std::optional<uint64_t> maximum_queue_size_;

  std::condition_variable enough_inputs_;
  std::condition_variable can_enqueue_;

  bool is_closed_ = false /* GUARDED_BY(mu_) */;
  std::deque<QueueItem> deque_ /* GUARDED_BY(mu_) */;

  const bool check_inputs_;
};

