Overview
Cross Margin
Portfolio Margining
Isolated Margin
Setting and Adjusting Isolated Margin
Isolated Margin and Mark Price
More Information
Overview
In the derivatives space, margin refers to the amount needed to enter into a leveraged position. Initial and Maintenance Margin refer to the minimum initial 
amount needed to enter a position and the minimum amount needed to keep that position from getting liquidated. As various users have varying trading strategies,
 BitMEX has employed two different methods of margining:

Cross Margin: Margin is shared between open positions. When needed, a position will draw more margin from the total account balance to avoid liquidation.

Isolated Margin: Margin assigned to a position is restricted to a certain amount. If the margin falls below the Maintenance Margin level, the position is liquidated.
However, you can add and remove margin at will under this method.

Cross Margin
Cross Margin, also known as “Spread Margin” is a margin method that utilises the full amount of funds in the Available Balance to avoid liquidations. 
Any Realised PNL from other positions can aid in adding margin on a losing position.

This margin method is useful for users who are hedging existing positions and also for arbitragers that do not wish to be exposed on one side of the
trade in the event of a liquidation.

Note that, by default all positions are initially set to “Cross Margin”.

Portfolio Margining
BitMEX DOES NOT offer portfolio margining. Unrealised profit may not be used to offset any unrealised losses, or as margin to open new positions. This is especially
 important for those traders who intend to trade the spread between two derivative contracts that share the same underlying. You must realize your profit by closing 
 a position in order for it to be used to offset losses on another contract.

Isolated Margin
In this mode, your liability is limited to the initial margin posted. In the event of a liquidation, any Available Balance you may have will not be used to add margin 
to your position.

Isolated Margin is useful for speculative positions. By isolating the margin the position uses, you can limit your losses to the initial margin set, and thus helps 
short-term speculative trade ideas that turned out incorrectly. In a volatile market, a highly leveraged position can lose equity quickly. However, note that although 
BitMEX aims to minimise liquidations from happening, in volatile markets highly-leveraged are more likely to be liquidated. For example, a 50x position will be 
liquidated after a 2% move against you.

When using Isolated Margin, you are able to adjust your leverage on the fly via the leverage slider.

Setting and Adjusting Isolated Margin
By default, Cross Margin is enabled. Users enable Isolated Margin on the order controls panel at the left side of the Trading Dashboard using the leverage slider. 
The further to the right you move the slider, the higher the leverage, and the less margin is used for the position. Note that the prefered leverage is effective 
per-contract and is saved, even if a user completely exits a position.

Once margin is isolated on a position, the amount of margin assigned to the position is adjustable. This allows you to choose a desirable leverage and liquidation price. 
Your liquidation price on the position is shown in the Open Positions tab and will update as you adjust your leverage.

Isolated Margin and Mark Price
During times of extreme volatility or during significant bull or bear runs, the markets may temporarily trade at a distance from the Mark Price.

If the price that you buy or sell at is significantly far away from the Mark Price, you will see an immediate unrealised loss on the position upon opening. 
However note that this does not mean that you have necessarily lost money. It is advisable that during these market conditions to pay attention to your liquidation 
price and avoid using the maximum leverage on Isolated Margin, since your position may be liquidated fairly quickly given the immediate unrealised loss the position 
saw upon opening.

More Information
Further information is available on:

The differences between Cross Margin and Isolated Margin
Adjusting your leverage