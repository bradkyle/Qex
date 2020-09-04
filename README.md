
store contains crud operations for given datums
service contains auxillary functionality for use in the api and for connecting engines?
pushing contains logic for pushing update events through the api to consumers: wss, grafana, fix etc.
ingress contains the logic for sensors .i.e deriving state from external sources:other exchanges etc.
engine contains the main logic for the exchange
    - audit contains logic to check balances etc. sum up correctly with wallets ~ configurable time
    - broker contains logic for managing events/orders etc. that are not part of the engine i.e. stop orders
    - core contains the main matching engine/orderbook logic
    - deleverage contains the main adl queue and deleverage logic
    - funding contains the worker that executes funding operations
    - index contains the index derivation worker
    - liquidation contains logic for the main liquidation engine.

common contains common logic
api contains the api methods for fix, grpc, rest and wss etc.
analytics contains the main monitoring function for all functionality