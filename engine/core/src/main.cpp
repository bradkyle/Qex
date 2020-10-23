
// set instrument singleton

// Maintain Minimal Local state for speed
// account
// inventory 
// instrument  
// order 
// set instrument singleton

// Account
// 

// Server
// =================================================================>

// Order ---------------------------------------->

// Place Limit Order
// Update the open order loss, 
 
// Amend Limit Order
// update a given limit order price, side, available margin
// etc.
// emit events, return responses etc.

// Cancel Limit Order
// update the open order loss of account, available margin
// etc.

// Place Market Order
// apply fill, update realized pnl where neccessary
// unrealized pnl, order margin, liquidate if neccessary
// ()

// Account ------------------------------------->

// Update Account State
// changes the state of an account, will affect later
// requests in the queue 

// Update Account Leverage
// run efficient checks to see if update is viable
// update unrealized pnl, pos margin, order margin etc.

// Update Account Position Type
// run efficient checks to see if update is viable

// Update Account Margin Type
// run efficient checks to see if update is viable
// update account margin type

// Update Inventory Leverage
// run simple check to see if update is viable
// update inventory 

// Instrument ---------------------------------->

// Apply Settlement 
// Settlement moves realized pnl into account balance/wallet etc.

// Apply Funding
// update the realized pnl to represent the funding supplied by queue

// Update Mark
// update inventory unrealized pnl of inventory and associated account etc.
// update open order loss of account and available balance
// get liquidateable accounts and send to 
// emit liquidation to liquidation engine
// emit account update events (for persistence)
// emit inventory update events (for persistence)

// Engine
// =================================================================>

boost::mutex imu_;
void engine() {
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
                        case PLACE_LIMIT_ORDER: // L
                            /* orderbook->place_market_order() */
                            break;

                        case AMEND_LIMIT_ORDER:
                            /* if can ammend limit order
                               if(orderbook->amend_limit_order(&res; event)) {
                                   inventory->emit_state(&res) 
                               }                               
                            */
                            break;

                        case CANCEL_LIMIT_ORDER:
                            /* if can cancel limit order
                                if() {

                                }
                            */
                            break;

                        case PLACE_MARKET_ORDER: 
                            break;

                        case UPDATE_INVENTORY:
                            break;

                        case APPLY_SETTLEMENT:
                            break;

                        case APPLY_FUNDING:
                            break;

                        case UPDATE_MARK:
                            break;
                    
                        default:
                            break;
                    }
                };
                imu_.unlock();
            }

            batch->set_responses();
        }
    } catch(std::exception& e) {

    };
    };


// Egress
// =================================================================>

void egress() {

    };

int main() {
    // shared ptr of instrument

    // shared ptr of ingress event queue (used for promises)
    
    // shared ptr of egress event queue (used for emitting events)

    // reload state into memory, shared ptr Engine

    // Start Ingress worker thread pool 

    // Start Egress worker thread pool

    // start grpc server (requests are added to ingress queue)
    };