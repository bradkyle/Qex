



class Engine    {

    // run 

    };

// Engine
// =================================================================>

boost::mutex imu_;
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
                        /* if can place market order 
                        if(orderbook->place_market_order(&res; event)) {
                            inventory->amend_limit_order(event);
                            inventory->emit_state(egress_queue); 
                            account->emit_state(egress_queue);
                            orderbook->emit_state(egress_queue);                                        
                        } 
                        */
                        break;

                    case AMEND_LIMIT_ORDER: // (orderId;price;size)
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
                        break;

                    case CANCEL_LIMIT_ORDER: // (orderId)
                        /* if can cancel limit order 
                        if(orderbook->amend_limit_order(&res; event)) {
                            inventory->amend_limit_order(event);
                            inventory->emit_state(egress_queue); 
                            account->emit_state(egress_queue);
                            orderbook->emit_state(egress_queue);
                        } 
                        */
                        break;

                    case PLACE_MARKET_ORDER: // (accountId;orderId;size;side)
                        /* if can place market order 
                        if(orderbook->place_market_order(&res; event)) {
                            inventory->amend_limit_order(event);
                            inventory->emit_state(egress_queue); 
                            account->emit_state(egress_queue);
                            orderbook->emit_state(egress_queue);                                        
                        } 
                        */
                        break;

                    case UPDATE_ACCOUNT:    // (accountId;state;marginType;positionType;leverage)
                        break;
                    
                    case UPDATE_INVENTORY:  // (accountId;side;leverage)
                        break;

                    case APPLY_SETTLEMENT:  // ()
                        break;

                    case APPLY_FUNDING:     // (fundingRate;fundingType)
                        break;

                    case UPDATE_MARK:       // (markPrice)
                        break;
                
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