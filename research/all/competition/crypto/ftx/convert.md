
{
  "fromCoin": "BTC",
  "toCoin": "USD",
  "size": 0.05
}

{
  "success": true,
  "result": {
    "quoteId": 1031
  }
}

{
  "success": true,
  "result": [
    {
      "baseCoin": "BTC"
      "cost": 0.05
      "expired": false,
      "filled": false,
      "fromCoin": "BTC",
      "id": 1031,
      "price": 7695.4,
      "proceeds": 384.77,
      "quoteCoin": "USD",
      "side": "sell",
      "toCoin": "USD"
    }
  ]
}

baseCoin	string	            BTC	
cost	number	0.05	        cost of accepting the quote in units of fromCoin
expired	bool	false	        if the quote is expired (if so, cannot accep tit)
filled	bool	false	        if the quote is already accepted
id	number	1031	
price	number	7695.4	        price in units of quoteCoin
proceeds	number	384.77	    proceeds of accepting the quote in units of toCoin
quoteCoin	string	            USD	
side	string	"sell"	        "sell" if fromCoin is baseCoin, otherwise "buy"
toCoin	string	USD	

{
  "success": true,
  "result": null
}