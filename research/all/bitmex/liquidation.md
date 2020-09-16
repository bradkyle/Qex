Most BitMEX contracts are highly leveraged. To keep these positions open, traders are required to hold a percentage of the value of the position on the exchange, known as the Maintenance 
Margin percentage. Minimum Maintenance Margin Requirements can be reviewed on the Risk Limits Page.

If you cannot fulfill your maintenance requirement, you will be liquidated and your maintenance margin will be lost.

You can review your liquidation price per position via the Open Positions Tab and adjust by adding additional margin via the Leverage Slider or via the Risk Limits tab.

Minimisation of Liquidations
Liquidation Process
Users on the Lowest Risk Limit tiers
Users on Higher Risk Limit tiers
System Gains and Losses
More Information
Minimisation of Liquidations
BitMEX uses Fair Price Marking for the purpose of avoiding liquidation due to illiquid markets or manipulation.

Risk Limits are also imposed that require higher margin levels for larger position sizes. This gives the BitMEX liquidation system more usable margin to effectively close large positions that 
would otherwise be difficult to safely close. If it is safe to do, larger positions are incrementally liquidated.

If a liquidation is triggered, BitMEX will cancel any open orders on the current contract in an attempt to free up margin and maintain the position. Orders on other contracts will still remain open.

Liquidation Process
BitMEX employs a partial liquidation process involving automatic reduction of maintenance margin in an attempt to avoid a full liquidation of a trader’s position.

Users on the Lowest Risk Limit tiers
BitMEX cancels any open orders in the contract.
If this does not satisfy the maintenance margin requirement then the position will be liquidated by the liquidation engine at the bankruptcy price.
Users on Higher Risk Limit tiers
The liquidation system attempts to bring a user down to a lower Risk Limit, and thus lower margin requirements by:

Attempting to bring a user down to a Risk Limit associated with their open orders and current position.
Cancelling any open orders and then attempting to bring a user down to a Risk Limit associated with their current position.
Submitting a FillOrKill order of the difference between the current Risk Limit position size and the position size to satisfy the margin requirement to avoid liquidation.
If the position is still in liquidation then the entire position is taken over by the liquidation engine and a limit order to close the position is placed at the bankruptcy price.
System Gains and Losses
If BitMEX is able to liquidate the position at better than the bankruptcy price, the additional funds will be added to the Insurance Fund.

If BitMEX is unable to liquidate the position at the bankruptcy price, BitMEX will spend the Insurance Funds on aggressing the position in the market in an attempt to close it. If this still does not 
close the liquidated order, this will then lead to an Auto-Deleveraging event.

More Information
Further information and examples of the Liquidation process are available.