{
    "exchangeFilters": [],
    "rateLimits": [
        {
            "interval": "MINUTE",
            "intervalNum": 1,
            "limit": 2400,
            "rateLimitType": "REQUEST_WEIGHT"
        },
        {
            "interval": "MINUTE",
            "intervalNum": 1,
            "limit": 1200,
            "rateLimitType": "ORDERS"
        }
    ],
    "serverTime": 1565613908500,
    "symbols": [
        {
            "symbol": "BTCUSDT",
            "status": "TRADING",
            "maintMarginPercent": "2.5000",
            "requiredMarginPercent": "5.0000",
            "baseAsset": "BTC",
            "quoteAsset": "USDT",
            "pricePrecision": 2,
            "quantityPrecision": 3,
            "baseAssetPrecision": 8,
            "quotePrecision": 8,
            "filters": [
                {
                    "minPrice": "0.01",
                    "maxPrice": "100000",
                    "filterType": "PRICE_FILTER",
                    "tickSize": "0.01"
                },
                {
                    "stepSize": "0.001",
                    "filterType": "LOT_SIZE",
                    "maxQty": "1000",
                    "minQty": "0.001"
                },
                {
                    "stepSize": "0.001",
                    "filterType": "MARKET_LOT_SIZE",
                    "maxQty": "1000",
                    "minQty": "0.001"
                },
                {
                    "limit": 0, 
                    "filterType": "MAX_NUM_ORDERS"
                },
                {
                    "multiplierDown": "0.7000",
                    "multiplierUp": "1.3000",
                    "multiplierDecimal": "4",
                    "filterType": "PERCENT_PRICE"
                }
            ],
            "orderTypes": [
                "LIMIT",
                "MARKET",
                "STOP",
                "STOP_MARKET",
                "TAKE_PROFIT",
                "TAKE_PROFIT_MARKET"
            ],
            "timeInForce": [
                "GTC", 
                "IOC", 
                "FOK",
                "GTX"
            ]
        }
    ],
    "timezone": "UTC"
}