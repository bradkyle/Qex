Overview of Auto-Deleveraging (ADL)
ADL Priority Deleveraging Ranking
Priority Ranking Calculation
More Information
Overview of Auto-Deleveraging (ADL)
When a trader’s position is liquidated, the position is taken over by the BitMEX liquidation engine. If the liquidation cannot be filled by the time the mark price reaches the bankruptcy price, the ADL system automatically deleverages opposing traders’ positions by profit and leverage priority.

The price at which a traders’ positions are closed out is the bankruptcy price of the initial liquidated order.

ADL Priority Deleveraging Ranking
At all times, your position in the queue is shown by an indicator. This indicator represents your priority in the queue in 20% increments:


In the above example, all “lights” are lit, which would mean your position is in the top percentile. In the case of a liquidation that is not able to be caught in the market, you may be deleveraged.

The Insurance Fund is used to prevent ADL. If it is depleted for a given contract, ADL will occur.

If you are deleveraged, you will be sent a notification. Open orders will be cancelled and you are free to re-enter.

Priority Ranking Calculation
Deleveraging priority is calculated by profit and leverage. More profitable and higher leveraged traders are deleveraged first.

The ranking calculation is as follows:

Ranking = PNL Percentage * Effective Leverage  (if PNL percentage > 0)
        = PNL Percentage / Effective Leverage  (if PNL percentage < 0)
where
  Effective Leverage = abs(Mark Value) / (Mark Value - Bankrupt Value)
  PNL percentage = (Mark Value - Avg Entry Value) / abs(Avg Entry Value)
  Mark Value = Position Value at Mark Price
  Bankrupt Value = Position Value at Bankruptcy Price
  Avg Entry Value = Position Value at Average Entry Price
The system splits these positions by longs and shorts and ranks the positions from highest to lowest.

More Information
Further information and examples of the Auto-Deleveraging process are available.

Auto-Deleveraging Further Information
Example of Auto-Deleveraging and the Ranking System
API Data
Auto-Deleveraging Further Information
BitMEX employs an Auto-Deleveraging (ADL) system as a margining method for its speculative derivative instruments as an evolution to the “Socialised Loss” system.

Socialised Loss systems have a few disadvantages:

A single risky trader can create a large loss for all traders, including low-risk traders.
Profit must be locked until rebalance or settlement in case of loss.
The ADL system aims to resolve loss uncertainty, allowing traders to make decisions as soon as the deleveraging event occurs, rather than wait for rebalance or settlement. Traders who become deleveraged will be immediately informed of their closeout price and size. They may then choose to re-enter the market.

Example of Auto-Deleveraging and the Ranking System
Let’s assume within the system there are 6 longs and their effective leveraged PnL score has been calculated. Note the higher the PnL Ranking, the higher their effective leveraged PnL.

Account	Quantity	PNL Ranking
1	10	3
2	10	6
3	20	1
4	30	4
5	20	5
6	10	2
The system will next rank these positions from the highest score to the lowest and calculate the quintile associated in that position.

Account	Quantity	PNL Ranking	Percentile
2	10	6	20%
5	20	5	40%
4	30	4	60%
1	10	3	80%
6	10	2	80%
3	20	1	100%
In the case of a liquidation, those users in the top percentiles will be deleveraged first. Let’s consider a short position that has been liquidated with size 20 and bankruptcy price of USD 650.

Accounts 2 and 5 will be deleveraged at the bankruptcy price of USD 650. Account 2 will have their entire position of 10 contracts closed, while the remaining 10 contracts from the short liquidation will be assigned to account 5.

Account 5 will thus have 10 contracts remaining (from 20). Depending on his/her effective leverage, account 5 may or may not remain in the lowest quintile.

Both users will be notified and given the opportunity to re-enter their positions.

API Data
For an example of how this process looks via the API, please see the WebSocket Documentation