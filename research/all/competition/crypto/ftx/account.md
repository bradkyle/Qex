{
  "success": true,
  "result": {
    "backstopProvider": true,
    "collateral": 3568181.02691129,
    "freeCollateral": 1786071.456884368,
    "initialMarginRequirement": 0.12222384240257728,
    "leverage": 10,
    "liquidating": false,
    "maintenanceMarginRequirement": 0.07177992558058484,
    "makerFee": 0.0002,
    "marginFraction": 0.5588433331419503,
    "openMarginFraction": 0.2447194090423075,
    "takerFee": 0.0005,
    "totalAccountValue": 3568180.98341129,
    "totalPositionSize": 6384939.6992,
    "username": "user@domain.com",
    "positions": [
      {
        "cost": -31.7906,
        "entryPrice": 138.22,
        "future": "ETH-PERP",
        "initialMarginRequirement": 0.1,
        "longOrderSize": 1744.55,
        "maintenanceMarginRequirement": 0.04,
        "netSize": -0.23,
        "openSize": 1744.32,
        "realizedPnl": 3.39441714,
        "shortOrderSize": 1732.09,
        "side": "sell",
        "size": 0.23,
        "unrealizedPnl": 0
      }
    ]
  }
}

backstopProvider	boolean	true	                        whether or not the account is a registered backstop liquidity provider
collateral	number	3568181.02691129	                    amount of collateral
freeCollateral	number	1786071.456884368	                amount of free collateral
initialMarginRequirement	number	0.12222384240257728	    average of initialMarginRequirement for individual futures, weighed by position notional. Cannot open new positions if openMarginFraction falls below this value.
liquidating	boolean	false	                                True if the account is currently being liquidated
maintenanceMarginRequirementnumber	0.07177992558058484	    Average of maintenanceMarginRequirement for individual futures, weighed by position notional. Account enters liquidation mode if margin fraction falls below this value.
makerFee	number	0.0002 -	
marginFraction	number	0.5588433331419503 -	            ratio between total account value and total account position notional.
openMarginFraction	number	0.2447194090423075	            Ratio between total realized account value and total open position notional
takerFee	number	0.0005	
totalAccountValue	number	3568180.98341129	            total value of the account, using mark price for positions
totalPositionSize	number	6384939.6992	                total size of positions held by the account, using mark price
username	string	                                        user@domain.com	
leverage	number	10.0	                                Max account leverage
positions	array		                                    See Get positions for details

{
  "success": true,
  "result": [
    {
      "cost": -31.7906,
      "entryPrice": 138.22,
      "estimatedLiquidationPrice": 152.1,
      "future": "ETH-PERP",
      "initialMarginRequirement": 0.1,
      "longOrderSize": 1744.55,
      "maintenanceMarginRequirement": 0.04,
      "netSize": -0.23,
      "openSize": 1744.32,
      "realizedPnl": 3.39441714,
      "shortOrderSize": 1732.09,
      "side": "sell",
      "size": 0.23,
      "unrealizedPnl": 0,
      "collateralUsed": 3.17906
    }
  ]
}

cost	number	-31.7906	                                Amount that was paid to enter this position, equal to size * entry_price. Positive if long, negative if short.
entryPrice	number	138.22	                                Average cost of this position after pnl was last realized: whenever unrealized pnl gets realized, this field 
                                                                     gets set to mark price, unrealizedPnL is set to 0, and realizedPnl changes by the previous value for 
                                                                     unrealizedPnl.
estimatedLiquidationPrice	number	152.1	
future	string	ETH-PERP	                                future name
initialMarginRequirement number	0.1	                        Minimum margin fraction for opening new positions
longOrderSize	number	1744.55	                            Cumulative size of all open bids
maintenanceMarginRequirement	number	0.04	            Minimum margin fraction to avoid liquidations
netSize	number	-0.23	                                    Size of position. Positive if long, negative if short.
openSize	number	1744.32	                                Maximum possible absolute position size if some subset of open orders are filled
realizedPnl	number	3.39441714	
shortOrderSize	number	1732.09	                            Cumulative size of all open offers
side	string	sell	                                    sell if short, buy if long
size	number	0.23	                                    Absolute value of netSize
unrealizedPnl	number	0.0	
collateralUsed	number	3.17906	