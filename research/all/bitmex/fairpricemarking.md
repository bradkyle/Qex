Overview
Calculation of Fair Price for Perpetual Contracts
Calculation of Fair Price for Futures Contracts
Impact Bid, Ask, and Mid Price
Fair Price Derivation
Exceptions
Last Price Protected Marking
Overview
BitMEX employs a unique system called Fair Price Marking to avoid unnecessary liquidations in its highly leveraged products. Without this system, unnecessary liquidations may occur if the market is being manipulated, is illiquid, or the Mark Price swings unnecessarily relative to its Index Price. The system is able to achieve this by setting the Mark Price of the contract to the Fair Price instead of the Last Price.

For Perpetual Contracts, the Fair Price is equal to the underlying Index Price plus a decaying Funding basis rate.

For Futures Contracts, the Fair Price is equal to the underlying Index Price plus an annualised Fair Value basis rate, known as the % Fair Basis.

All ADL contracts are subject to Fair Price Marking. Also note that Fair Price Marking only affects the Liquidation Price and Unrealised PNL, it does not affect Realised PNL.

Note: This means that you may see a positive or negative Unrealised PNL immediately after an order executes. This happens when the Fair Price is slightly different from the Last Price. This is normal and does not mean you have lost money, but be sure to keep an eye on your Liquidation Price to avoid a premature liquidation.

Further information on the composition and calculation of BitMEX indices is available.

Calculation of Fair Price for Perpetual Contracts
The Fair Price for a Perpetual Contract is calculated using only the Funding Basis rate:

Funding Basis = Funding Rate * (Time Until Funding / Funding Interval)
Fair Price    = Index Price * (1 + Funding Basis)
For further information on perpetual contract funding calculations and examples please see the Funding Section in the Perpetual Contracts Guide.

Calculation of Fair Price for Futures Contracts
The Fair Price marking calculation for Futures Contracts is slightly different to a Perpetual Contract, and is done by comparing the Impact Mid Price of a contract to its underlying Index Price. This is used to then calculate the % Fair Basis which is then used in the derivation of the Fair Price.

Impact Bid, Ask, and Mid Price
Impact Mid Price = Average (Impact Bid Price, Impact Ask Price) where;
Impact Bid Price = The average fill price to execute the Impact Margin Notional on the Bid side
Impact Ask Price = The average fill price to execute the Impact Margin Notional on the Ask side
The Impact Margin Notional is the notional available to trade with 0.1 XBT worth of margin (i.e. 0.1 XBT / Initial Margin) and is used to determine how deep in the order book to measure either the Impact Bid or Ask Price.

For Example:

Contract	Initial Margin	Impact Margin Notional
XBT Quarterly	1%	0.1 XBT / 0.01 = 10 XBT
XBJ Quarterly	4%	0.1 XBT / 0.04 = 2.5 XBT
ETC Weekly	10%	0.1 XBT / 0.10 = 1 XBT
Fair Price Derivation
Once BitMEX has calculated the Impact Mid Price, it can use this number to calculate the % Fair Basis. The % Fair Basis will then be used to calculate the Fair Value of the futures contract which is added to the Index Price to finally create the Fair Price which is used for marking purposes.

% Fair Basis = (Impact Mid Price / Index Price - 1) / (Time To Expiry / 365)
Fair Value   = Index Price * % Fair Basis * (Time to Expiry / 365)
Fair Price   = Index Price + Fair Value
For Example

Impact Mid Price = $105
Underlying Index = $100
Time To Expiry = 30 Days

% Fair Basis = ($105 / $100 - 1) / (30 / 365) = 60.8%
Fair Value = $100 * 60.8% * (30/365) = $5
Fair Price = $100 + $5 = $105
Note on Calculation: The % Fair Basis is updated each minute but only if the difference between the Impact Ask Price and Impact Bid Price is less than the maintenance margin of the futures contract. After it has been updated the Fair Price will be equal to the Impact Mid Price, and then the Fair Price will float with regard to the Index Price and the time-to-expiry decay on the contract until the next update.

Exceptions
Occasionally, due to index instability, a contract may need to be moved to an alternative mode, LastPriceProtected. Historically this has happened on the XBJ contracts due to pricing anomalies.

In the case of such anomalies, notice will be sent as the marking method is changed.

Last Price Protected Marking
Last Price Protected is a marking mode that functions similarly to simple Last Price marking, but with some protections for our users as not to cause unnecessary liquidations.

A price band is created equal to 1 maintenance margin (0.5x each way) around the previously-calculated Mark Price (also known as the Fair Price, calculated above).

The Mark Price is equal to the Last Price, but only within this band created by the Fair Price. If the band moves, the Mark Price will stay. It is allowed to move toward the band but not away from it.

For API consumers, this field is available on the instrument feed as lastPriceProtected.