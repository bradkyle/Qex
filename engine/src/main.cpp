#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "arithmetics.grpc.pb.h"
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

class EngineServiceImpl final : public Engine::Service {
    // HaltEngine

    };
// set instrument singleton

// Maintain Minimal Local state for speed
// account (full)
// inventory (open only)
// instrument (singleton)
// order (full)
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