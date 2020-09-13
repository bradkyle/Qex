

// Create a request queue per instrument + engine instance
// limit the amount of messages recieved to .e.
// all write requests are added to queue
// services that implement write functionality will do so
// through the given queue and 