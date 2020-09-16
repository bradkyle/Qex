BitMEX has implemented several different order types to assist with users’ unique trading and hedging strategies. This section outlines the various order types available with some examples. To see the fees charged for various order types, please click here.

Market Orders
Limit Orders
Limit Order Example
Stop Orders
Stop Limit Order Example
Trailing Stop Order Example
Take Profit Orders
Take Profit Limit Order Example
Advanced Order Functions
Hidden Orders
Hidden Order Example
Iceberg Orders
Iceberg Order Example
Post Only Orders
Post-Only Order Example
Close On Trigger Orders
Close On Trigger Example
Pegged Orders (API only)
Pegged Order Examples
Market Orders
A market order is an order to be executed immediately at current market prices. Traders use this order type when they have an urgent execution. Pay attention to the orderbook when selecting this order type, otherwise a large market order may “walk the book” and incur market-impact costs.

User Inputs: Quantity

Limit Orders
Limit orders are used to specify a maximum or minimum price the trader is willing to buy or sell at. Traders use this order type to minimise their trading cost, however they are sacrificing guaranteed execution as there is a chance the order may not be executed if it is placed deep out of the market.

User Inputs: Quantity, Limit Price

Limit Order Example
Quantity = 10 Contracts
Limit Price = 100
Direction = Buy
A bid of 10 contracts will be placed in the market with a Limit Price of 100.

Stop Orders
A Stop Order is an order that does not enter the order book until the market reaches a certain Trigger Price. Traders use this type of order for two main strategies:

As a risk-management tool to limit losses on existing positions, and
As an automatic tool to enter the market at a desired entry point without manually waiting for the market to place the order.
BitMEX has three types of Stop Orders:

Stop Market Order - A Market Order will be placed when the market reaches the Trigger Price.
Stop Limit Order - A Limit Order will be placed when the market reaches the Trigger Price.
Trailing Stop Order - A Trailing Value is set; if the price reverts by an amount equal to the Trailing Value, a Market Order triggers.
A positive Trail Value indicates a trailing Buy whilst a negative Trail Value indicates a trailing Sell.

For all Stop Orders, the Trigger Price can be specified as either the Last Price, Mark Price or the underlying Index Price.

Stop Orders can be selected in the Dropdown list, by clicking on the three vertical dots, and will show you the Stop Price, Triggering Price and Status. There are three distinct Status events that are shown during the execution of a Stop Order:

Untriggered - The Trigger Price has not reached a level to trigger the Stop order.
Triggered - The Trigger Price has been reached but no order has been filled.
Filled - The Stop Order has been triggered and the order has been filled.
Users may cancel Stop Orders by clicking the cancel button.

Stop orders are implemented as a brokerage function and triggered stop orders are not guaranteed to be executed on the exchange at the exact time of triggering. Once a stop order is triggered, an order is submitted to the exchange; however, in a fast-moving market, users may experience slippage.

User Inputs: Quantity, Stop Price, Limit Price, Trigger

Stop Limit Order Example
Quantity = 10 Contracts
Stop Price = 100
Limit Price = 90
Trigger = Mark Price
Direction = Buy
In this example, the user has selected a Stop Limit Buy Order with the Mark Price set as the Trigger Price. If the Mark Price hits 100, then a Limit Order will be placed for 10 contracts at 90.

User Input: Quantity, Trail Value, Trigger

Trailing Stop Order Example
Quantity = 10 Contracts
Trail Value = 5
Trigger = Mark Price
Direction = Buy (since the Trail Value is positive)
Once the user places this order type, a buy Market Order of 10 contracts will only be placed when the Mark Price rises more than the Trail Value of 5 here. However, if the Mark Price falls, then this order type will chase it and will only execute if the Mark Price rises by the Trail Value of 5 from wherever it drops to.

Take Profit Orders
A Take Profit Order is somewhat similar to a Stop Order, however instead of executing when the price moves against the position, the order executes when the price moves in a favourable direction. Traders predominately use Take Profit orders as opposed to Limit orders to increase the chances of closing out a position, or “taking profit”. They do this by specifying a Market or Limit order instruction to be executed once the market reaches the predefined Trigger Price.

BitMEX has two types of Take Profit Orders:

1. Take Profit Market Order - A Market Order will be placed when the market reaches the Trigger Price. 2. Take Profit Limit Order - A Limit Order will be placed when the market reaches the Trigger Price.

For all Take Profit Orders, the Trigger Price can be specified as either the Last Price, Mark Price or the underlying Index Price.

Take Profit Orders can be selected in the Dropdown list, by clicking on the three vertical dots, and will show you the Limit Price, Triggering Price and Status. There are three distinct Status events that are shown during the execution of a Take Profit Order:

1. Untriggered - The Trigger Price has not reached a level to trigger the Take Profit order. 2. Triggered - The Trigger Price has been reached but no order has been filled. 3. Filled - The Take Profit Order has been triggered and the order has been filled.

Users may cancel Take Profit Orders by clicking the cancel button.

User Inputs: Quantity, Trigger Price, Limit Price, Trigger

Take Profit Limit Order Example
Quantity = 10 Contracts
Trigger Price = 100
Limit Price = 90
Trigger = Mark Price
Direction = Sell
In this example, the user has selected a Take Profit Limit Sell Order with the Mark Price set as the Trigger Price. If the Mark Price hits 100, then a Limit Order will be placed for 10 contracts at the Limit Price of 90. A trader would set a Limit Price below the Trigger Price if they want to increase the chance of an execution when triggered.

Advanced Order Functions
This section will introduce users to various order functions they can use on top of the existing order types above.

Hidden Orders
A Hidden Order is a Limit Order that is not visible on the public orderbook. Users can access it via the Limit Order, Stop Limit Order or Take Profit Limit Order selection via checking the “Hidden” box. Traders use this order type when they don’t want to inform the market of their trading intentions.

User Input: Quantity, Limit Price, Hidden Box Checked

Hidden Order Example
Quantity = 10 Contracts
Limit Price = 100
Hidden Box = Checked
Direction = Buy
A buy Limit Order for 10 contracts with a Limit Price of 100 will be submitted to the market and will not be visible to other traders. It will be executed as per a normal Limit Order based on time / price priority.

Iceberg Orders
An Iceberg Order is a Hidden Order where a part of the order is displayed on the public orderbook. Since savvy traders are able to identify Hidden Orders, some traders prefer to use this order type in an attempt to be indistinguishable from traders continously refilling their order. You can access this order type by selecting either the Limit Order, Stop Limit Order or Take Profit Limit Order and then checking the “Hidden” box and inputting a quantity to display.

User Input: Quantity, Limit Price, Hidden Box Checked, Display Quantity

Iceberg Order Example
Quantity = 10 Contracts
Limit Price = 100
Hidden Box = Checked
Display Quantity = 1 Contract
Direction = Buy
A buy Limit Order for 10 contracts with a Limit Price of 100 will be submitted to the market. Only a bid for 1 contract will be visible to other traders. If someone submits a sell Order for 3 contracts at 100 then 3 contracts will be executed from this order. After that, another bid for 1 contract will appear at 100 to other traders. As such, there will now be 7 contracts left remaining, with 1 only visible.

Post Only Orders
Post Only Orders are Limit Orders that are only accepted if they do not immediately execute. That is, Post Only Orders never take liquidity. Market makers use Post Only Orders in order to only submit passive orders so as to earn the Maker rebate. This order type can be accessed from the Limit Order, Stop Limit Order or Take Profit Limit Order selection by checking the “Post-Only” box.

User Input: Quantity, Limit Price, Post-Only Box Checked

Post-Only Order Example
Quantity = 10 Contracts
Limit Price = 102
Post-Only Box = Checked
Direction = Buy
Best Ask = 101
If the Post-Only box was not checked in this example, then this order would execute in the market against the Best Ask of 101 and the order would pay the Taker fee. Given the Post-Only box is checked, this order will not execute and be cancelled. Only if the Best Ask was higher than 102 will this order be placed in the market.

Close On Trigger Orders
Close On Trigger is an additional order type specification that can be added to most of the above Stop and Take Profit Order types. It can be utilised by checking the “Close On Trigger” box. It is considered a “high-priority” order and if enough margin is not present to execute, it will attempt to cancel other open orders in the same symbol. This order may only be used to reduce a position and will automatically cancel if it would increase it. Traders use this order type in case of market reversals.

User Input: Close On Trigger Box Checked

Close On Trigger Example
Existing Position = 10 Contracts
Quantity = 10 Contracts
Direction = Sell
Close On Trigger = Checked
A user has 3 existing buy Limit Orders in the market, and places a Stop Limit Sell Order with the “Close On Trigger” box checked. When the Stop executes, it reduces the position down to zero. Let’s assume there was not enough margin present in the account to execute this - in that case, the three limit orders will be canceled or amended down to free margin, starting with the ones farthest away from the market.

Pegged Orders (API only)
Pegged orders allow users to submit a limit price relative to the current market price. The limit price is set once when the order is submitted and does not change with the reference price. This order type is not intended for speculating on the far touch moving away after submission - we consider such behaviour abusive and monitor for it.

Two peg types are available:

PrimaryPeg - price is set relative to the near touch price
MarketPeg - price is set relative to the far touch price
See the API Explorer for complete documentation on the Pegged order type

Pegged Order Examples
orderQty = 100
execInst = Fixed
pegPriceType = PrimaryPeg
pegOffsetValue = 0
Submit a buy order at the best price

orderQty = 100
execInst = Fixed
pegPriceType = MarketPeg
pegOffsetValue = -1
Submit a buy order at one unit (contract value) below the best ask price