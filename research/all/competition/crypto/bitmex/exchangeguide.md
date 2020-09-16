Placing Orders
Margin and Profit & Loss (PNL)
Perpetual and Futures Contracts
Funding and Settlement
Market Disruption Event (MDE)
Placing Orders
You may place buy and sell orders of various types in the Place Order tab of the Trading Dashboard.

When a trader places a buy or sell order, before they are allowed to submit the order the system will check that they have enough Available Balance to reserve the Initial Margin. If the trader has an existing position in that instrument, it will also check that they have enough available balance to cover the change in Maintenance Margin and PNL, should the position be priced at the order price. If they have enough funds then they are allowed to place the order. Note: Net open orders that have not been filled or canceled will reduce the available balance by the initial margin of those net orders.

Margin and Profit & Loss (PNL)
Before you are able to trade you first must deposit Bitcoin to fund your margin account. All margin and PNL are denominated in Bitcoin on BitMEX. You should first review the terminology behind the Margin Terms.
Perpetual and Futures Contracts
The following are important rules regarding Initial Margin (IM):

For Buy orders the Initial Margin required = (IM * Contracts * Limit Bid Price * Multiplier). Commission is reserved using the limit bid price; however, the actual commission paid will be calculated based on the final execution price.

For Sell orders the Initial Margin required = (IM * Contracts * Max (Limit Offer Price, Best Bid) * Multiplier). Commission is reserved using the limit offer price or the best bid for that contract, whichever is higher. The actual commission paid will be calculated based on the final execution price.

Traders are not charged Initial Margin if their order will reduce their position size.

If a trader has both Bids and Offers in the market, initial margin will only be charged on the Net amount of Bids (Bid orders - Sell orders). The Sell orders will still be charged initial margin unless they reduce the current position size. For example, if a trader bids 20 contracts for $100 and offers 15 contracts for $150, he will only be charged initial margin on his net bids of 5 contracts (20 - 15) and on his offers of 15 contracts.

If a contract uses Fair Price Marking initial margin will be calculated differently. If a buy order is placed above the mark price, or if a sell order is placed below the mark price then the trader must fully fund the difference between the order price and the mark price. For example, if the mark price is $100 and the trader submits a bid order for 10 contracts at $110, then the initial margin required = (IM * 10 contracts * $110 * Multiplier) + (100% * 10 contracts * ($110 - $100) * Multiplier).

Maintenance Margin (MM) calculated based on the Mark Price of that contract.

For all positions the Maintenance Margin required = (MM * Contracts * Mark Price * Multiplier). The amount of commission applicable to close out all your positions will also be added onto your maintenance margin requirement. This is the minimum amount of margin you must maintain to avoid liquidation on your position .
Funding and Settlement
Perpetual contracts on BitMEX are subject to Funding. Examples of Funding Calculations are found under each perpetual Contract Specification. Funding History is also available on all perpetual contracts.

Perpetual contracts do not settle, and therefore do not incur a settlement fee.

At the Settlement of a contract, the position will close out at the Settlement Price.

Once a contract has expired, the lifetime profit and loss of that contract will be added to the traders Bitcoin balance. This contract will no longer appear on the Positions section.

All calculations done by BitMEX are final.

Market Disruption Event (MDE)
In the event that an exchange that contributes to the Index Price experiences an outage, BitMEX may declare an MDE and will inform traders how the settlement or expiry date of affected contracts will be altered.

Traders will be notified via an email announcement and the declaration of an MDE will be predominently displayed on the trading dashboard.
The declaration of a MDE is at the full discretion of BitMEX, and all decisions are final.