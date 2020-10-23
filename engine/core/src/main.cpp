
// set instrument singleton

// \l queue
// Maintain Minimal Local state for speed
// .model.account
// .model.inventory 
// .model.instrument  
// .model.order 
// set instrument singleton

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
int main() {
    // shared ptr of ingress event queue (used for promises)
    
    // shared ptr of egress event queue (used for emitting events)

    // Start Ingress worker thread pool

    // Start Egress worker thread pool

    // start grpc server (requests are added to ingress queue)
    };