BitMEX indices are composite, meaning that they are calculated using a number of data sources. BitMEX currently has 12 data sources: 
Binance, Binance US, Bitstamp, Bittrex, Coinbase, Gemini, Huobi, Itbit, Kraken, LBank, OKEX, Poloniex of which 11 are currently active in the indices.

Update Schedule
Example index calculation for .BXBT_NEXT
Index Weight Methodology
Index Protection Rules
Aiming to be representative of the underlying asset’s market consensus price, each BitMEX index is calculated as a weighted average of the Last Price for each constituent exchange. 
Index prices are calculated and published every 5 seconds. The index weights are shown in the table below. The constituents and index weights are reviewed and updated on a quarterly 
basis. Changes will be announced on the BitMEX website, on the BitMEX blog and via the BitMEX RSS feed, with three weeks notice before implementation. The BitMEX “NEXT” indices will 
be published at that time to track the hypothetical price of the indices with the new weights.

BitMEX Index Weights, assuming no constituent exchanges have been excluded due to Index Protection Rules, last updated 26 June 2020 at 12:00:05 UTC. For current weights incorporating any exclusions refer to the relevant Composite Index Breakdown.


USD Index Family

Binance US	Bitstamp	Bittrex	Coinbase	Gemini	Kraken
.BXBT	-	25.73%	2.63%	46.98%	6.69%	17.97%
.BETH	-	15.37%	-	56.18%	6.83%	21.62%
.BXRP	-	64.07%	-	28.34%	-	7.59%
.BBCH	-	19.54%	-	68.58%	-	11.88%
.BLTC	-	17.51%	-	75.17%	-	7.32%
.BUSDT	15.53%	-	5.39%	-	-	79.08%

USDT Index Family

Binance	Huobi	LBank	OKEX
.BADAT	67.23%	29.29%	-	3.48%
.BEOST	23.93%	38.67%	15.73%	21.67%
.BLINKT	60.45%	28.51%	-	11.04%
.BXTZT	55.41%	13.47%	-	31.12%

XBT Index Family

Binance	Bittrex	Coinbase	Huobi	Kraken	Poloniex
.BETHXBT	58.55%	-	5.77%	26.83%	3.30%	5.55%
.BXRPXBT	57.28%	2.89%	6.30%	21.82%	-	11.71%
.BBCHXBT	49.69%	-	8.51%	41.80%	-	-
.BLTCXBT	59.37%	-	10.45%	23.30%	-	6.88%
.BADAXBT	81.72%	7.06%	-	8.20%	3.02%	-
.BEOSXBT	53.89%	-	3.87%	42.24%	-	-
.BTRXXBT	73.26%	-	-	26.74%	-	

The BitMEX index weights are computed using volume data obtained directly via API connection from each of the constituent exchanges listed above.
 Proprietary mechanisms are used to identify malformed and anomalous data, which is discarded. The index weight calculation 
 removes constituents with insufficient trade volume.
For the avoidance of doubt, and in accordance with BitMEX Terms of Service, HDR Global Trading Limited (operator of the BitMEX trading 
platform) accepts no responsibility for the accuracy of any volume (or other) data received from any exchange and used to calculate the 
value of any BitMEX index and excludes all liability for any claimed losses arising in connection with its calculation and publication 
of any such index.

For further information see the individual index and index weights p