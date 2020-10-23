

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

// Server