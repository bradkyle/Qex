Overview
BitMEX imposes risk limits on all trading accounts to minimise the occurrence of large liquidations on margined contracts.

As users amass larger positions, they pose a risk to others on the exchange who may experience a deleveraging event if the position cannot be fully liquidated. 
The Step model helps avoid this by increasing margin requirements for large positions.

Dynamic Risk Limits
Each instrument has a Base Risk Limit and Step. These numbers combined with the base Maintenance and Initial Margin requirements are used to calculate your full margin 
requirement at each position size.

As the position size increases, the maintenance and initial margin requirements will increase. Users must authorize a higher or lower risk limit on the Positions panel. 
Margin requirements will automatically increase and decrease as your risk limit changes.



Formulas
Term	Formula	XBTUSD Example (1 Step)
New Maintenance Margin %	Base MM % + ( Steps * Base MM % )	0.35% + ( 1 * 0.35% ) = 0.70%
New Initial Margin %	Base IM % + ( Steps * Base MM % )	1.00% + ( 1 * 0.35% ) = 1.35%
XBT Maintenance Margin	New MM * Gross XBT Position Value	0.70% * 300 XBT = 2.1 XBT
More Information
Further information is available on:

How to Adjust Risk Limits
Trade Examples