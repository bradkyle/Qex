



class Engine    {

    
    // State Loading Utils  
    // =================================================================>

    
    // Main engine loop  
    // =================================================================>


    bool place_limit_order() {
        /* if can place market order 
        if(orderbook->place_market_order(&res; event)) {
            inventory->amend_limit_order(event);
            inventory->emit_state(egress_queue); 
            account->emit_state(egress_queue);
            orderbook->emit_state(egress_queue);                                        
        } 
        */
       egress_queue_.push(); // account state
       egress_queue_.push(); // inventory state
       egress_queue_.push(); // orderbook update
       egress_queue_.push(); // new limit order 
    };

    bool amend_limit_order() { 
        /* if can ammend limit order (price;size)
            if(account->can_amend_limit_order(&res;event)){
                if(orderbook->amend_limit_order(&res; event)) {
                    inventory->amend_limit_order(event);
                    inventory->emit_state(egress_queue); 
                    account->emit_state(egress_queue);
                    emit_state(egress_queue);
                }     
            }                          
        */

       egress_queue_.push(); // account state
       egress_queue_.push(); // inventory state
       egress_queue_.push(); // orderbook update
       egress_queue_.push(); // amended order 
    };

    bool cancel_limit_order() {
         /* if can cancel limit order 
            if(orderbook->amend_limit_order(&res; event)) {
                inventory->amend_limit_order(event);
                inventory->emit_state(egress_queue); 
                account->emit_state(egress_queue);
                orderbook->emit_state(egress_queue);
            } 
        */

       egress_queue_.push(); // account state
       egress_queue_.push(); // inventory state
       egress_queue_.push(); // orderbook update
       egress_queue_.push(); // new order 
    };

    bool place_market_order() {
        /* if can place market order 
        if(orderbook->place_market_order(&res; event)) {
            inventory->amend_limit_order(event);
            inventory->emit_state(egress_queue); 
            account->emit_state(egress_queue);
            orderbook->emit_state(egress_queue);                                        
        } 
        */
       egress_queue_.push(); // account state
       egress_queue_.push(); // inventory state
       egress_queue_.push(); // orderbook update
       egress_queue_.push(); // new order 
    };

    bool update_account() {
        
        egress_queue_.push(); // account update
        egress_queue_.push(); // inventory update
    };

    bool update_inventory() {
        egress_queue_.push(); // account update
        egress_queue_.push(); // inventory update
    };

    bool apply_settlement() {
        egress_queue_.push(); // account update
        egress_queue_.push(); // inventory update
        egress_queue_.push(); // instrument upadate
    };

    bool apply_funding() {

    };

    bool update_mark() {

    };

    // Main engine loop  
    // =================================================================>

    void run() {
        try {
            while (true) {
                Batch batch = ingress_queue->get_batch();
                
                {
                    imu_.lock();
                    BatchResponses res;
                    for(int i=0;i<batch.size();i++) {
                        Event event = batch.get_event(i);
                        switch (event.kind())
                        {
                            case PLACE_LIMIT_ORDER: // (accountId;orderId;size;side;price)
                                place_limit_order(event;&res);
                                break;

                            case AMEND_LIMIT_ORDER: // (orderId;price;size)
                                amend_limit_order(event;&res);
                                break;

                            case CANCEL_LIMIT_ORDER: // (orderId)
                                cancel_limit_order(event;&res);
                                break;

                            case PLACE_MARKET_ORDER: // (accountId;orderId;size;side)
                                place_market_order(event;&res);
                                break;

                            case UPDATE_ACCOUNT:    // (accountId;state;marginType;positionType;leverage)
                                update_account(event;&res);
                                break;
                            
                            case UPDATE_INVENTORY:  // (accountId;side;leverage)
                                update_inventory(event;&res)
                                break;

                            case APPLY_SETTLEMENT:  // ()
                                apply_settlement(event;&res);
                                break;

                            case APPLY_FUNDING: 
                                apply_funding(event;&res);
                                break;
                            case UPDATE_MARK:
                                update_mark(event;&res);
                                break
                        
                            default:
                                break; // todo fail res
                        }
                    };
                    imu_.unlock();
                }

                batch->set_responses();
            }
        } catch(std::exception& e) {

        };
    };

    private:
        boost::mutex imu_;
        BatchingQueue ingress_queue_;
        boost::lockfree::spsc_queue<int> egress_queue_;
        // ingress queue
        // egress queue
};