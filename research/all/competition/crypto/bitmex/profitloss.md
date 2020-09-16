This guide is meant to explain the concepts of unrealised and realised profit and loss (PNL).

Example 1, Buying and Selling
Perpetual Contracts
Example 2, Funding Fees
Example 3, Trading Fees
Example 4, Realised PNL Accounting
Example 1, Buying and Selling
Perpetual Contracts
John is long 1,000 XBTUSD contracts with an average entry price of $1,000. The mark price of XBTUSD is currently $1,250.

John’s unrealised PNL is based on the difference between his average entry price and the mark price.

Unrealised Profit = ($1/$1,000 - $1/$1,250) * 1,000 = 0.20 XBT

The last price of XBTUSD is $1,500. However for the calculation of unrealised PNL, the mark price is used not the last price. To understand why, 
please read Fair Price Marking.

John decides to sell 500 XBTUSD contracts at $1,500 and realise some profit.

John’s realised PNL is based on the difference between his average entry price and the price at which he sells XBTUSD.

Realised Profit = ($1/1,000 - $1/$1,500) * 500 = 0.17 XBT

Realised PNL is based on where you can actually buy or sell your position, which in most cases is not the mark price. If John had sold his 500 contracts at the mark price of $1,250, 
he would have a realised profit of 0.10 XBT.

Example 2, Funding Fees
BitMEX has a type of derivative contract called a Perpetual Contract. Buyers and sellers of perpetual contacts pay and receive funding fees periodically throughout the trading day. 
To learn more, please read the Perpetual Contracts Guide.

John is trading XBTUSD, which is a perpetual contract. Every 8 hours, there is a funding fee. The funding fee is currently 1%, and is paid from buyers to sellers.

John is currently long 100 XBT worth of XBTUSD. The position has no realised PNL. It is funding time and John must pay 1 XBT because he is long XBTUSD. After the funding fee has 
been paid, John’s realised PNL is now -1 XBT.

If John had been short 100 XBT worth of XBTUSD instead, he would have received 1 XBT. His realised profit would then be 1 XBT instead of -1 XBT.

Example 3, Trading Fees
All trading fees are accounted for through realised pnl.

John bought XBTUSD. The market has not moved. His unrealised PNL is 0, but his realised PNL is negative. John’s realised PNL is negative because he paid a taker fee when he bought XBTUSD.

If John had placed a passive limit order, he would be classified as a maker once the order was executed. As a maker, John would have been paid a rebate on the trade. 
In that situation, his unrealised PNL would be 0 and realised PNL positive.

Example 4, Realised PNL Accounting
Realised PNL is displayed in different locations on the BitMEX trading dashboard depending on whether you are merely reducing the size of an existing position, or closing it entirely.

If you have an open position with a realised profit of 10 XBT, this amount will show on the Open Positions tab.

If you completely close the same position and you realise a profit of 10 XBT, this 10 XBT will be shown on the Closed Positions tab.

If you then create a new position on the same contract, realised PNL will be reset to 0 XBT on the Open Positions tab. Realised PNL resulting from a partial closure of this new position
will be displayed on the Open Positions tab.

If you then completely close this new position, any realised PNL will be added to that symbol on the Closed Positions tab.