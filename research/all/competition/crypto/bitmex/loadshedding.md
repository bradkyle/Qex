At BitMEX, one of the most frequent questions we receive is about the behaviour and inner workings of our load shedding function, also known as “overload”.

Submitting an Order
Order management requests (i.e. new/amend/cancel orders and leverage changes) are placed in a single processing queue, and processed by the BitMEX trading engine in the order 
they arrive (first-in-first-out). This ensures that all requests are executed in the order they are received.

During times of extraordinary demand, order management requests arrive faster than they can be processed. As the queue depth grows, requests joining the back of the queue will wait 
longer, which can result in traders waiting several seconds for their requests to be processed and receive a response.

To maintain acceptable response times for traders (i.e. less than a few seconds), the queue has a maximum depth after which new requests are immediately rejected with a 503 status code. 
This mechanism gives immediate feedback to traders who can then choose to resubmit or amend. Without a maximum queue depth (i.e. an unbounded queue), if the platform were to receive many order
 management requests in a short period of time, the queue would grow very long. With a long queue, response times for user requests could grow into the minutes. The load shedding mechanism 
 is a standard technique that exists specifically to prevent this from happening, and to keep response times reasonable for users.

Non-full Queue
When the queue of order management requests is not full, then new requests just join the back of the queue as usual.

Non Full Queue

Placing an order when the queue of outstanding requests is not full

Load Shedding
When the rate of order management requests received is higher than the rate at which they can be processed, the queue of outstanding requests becomes full. An order management request received 
at this time will be rejected and the user will be notified. Note: there is a specific subset of order management requests detailed below that are exempt from being load-shed, and will join the 
back of the queue as usual.

Full Queue

Placing an order when the queue of outstanding requests is full

The determination of which order management request is accepted and which is rejected is based purely on the depth of the queue at the time the request is received. If an empty slot is available 
at the time an order request is received, it is accepted and joins the back of the queue. Otherwise, it is rejected.

Requests Exempt from Load Shedding
BitMEX has enacted a policy whereby certain order management requests are accepted even if the queue has reached its maximum depth. This provides a backstop for traders who decide they would rather 
exit a position or remove orders during high-volatility periods. These actions are limited to order cancellations and close orders and are summarised in the table below. Please note that all order 
management requests, including those exempt from being load-shed, join the back of the queue. If the queue is large, the time a request stays in queue before processing will increase. 
Exempt requests aren’t processed more quickly than any other request joining the queue.

Requests Exempt from Load Shedding	Non-Exempt Requests
Cancel Order (individual, bulk, and all)
Close Limit Order (full position)
Close Market Order (full position)
New Order (except Exempt types)
Amend Order
Position Leverage/Margin Changes
All Bulk Order Requests (API)
Exempt: Order Cancellation

Order Cancel

Web: Use the Cancel button under the Orders tab.
API: Cancel orders via DELETE /api/v1/order.
Exempt: Position Close Position Close

Web: Use either the Close or Market button under the Positions tab.
API: Use the “Close” execInst on POST /api/v1/order with no orderQty. The absence of a quantity, in combination with Close, is interpreted as your full position size. Close orders containing a quantity are subject to load shedding, as are bulk orders, even when only one is submitted.
Further Information
We are working daily to improve system performance and reduce the occurrences of load shedding. As we deliver enhancements and the throughput of the trading engine increases, the queue will process more quickly. With this additional performance, we periodically increase the maximum queue depth to allow more orders to be placed without being load-shed. We have done this three times in 2018 and once already in 2019.

We appreciate your support and use of BitMEX. As always, if you have questions or comments about this topic, please Contact Support.