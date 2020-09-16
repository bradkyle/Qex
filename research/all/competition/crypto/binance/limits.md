LIMITS
The /fapi/v1/exchangeInfo rateLimits array contains objects related to the exchange's RAW_REQUEST, REQUEST_WEIGHT, and ORDER rate limits. These are further defined in the ENUM definitions section under Rate limiters (rateLimitType).
A 429 will be returned when either rate limit is violated.
 Binance has the right to further tighten the rate limits on users with intent to attack.
IP Limits
Every request will contain X-MBX-USED-WEIGHT-(intervalNum)(intervalLetter) in the response headers which has the current used weight for the IP for all request rate limiters defined.
Each route has a weight which determines for the number of requests each endpoint counts for. Heavier endpoints and endpoints that do operations on multiple symbols will have a heavier weight.
When a 429 is received, it's your obligation as an API to back off and not spam the API.
Repeatedly violating rate limits and/or failing to back off after receiving 429s will result in an automated IP ban (HTTP status 418).
IP bans are tracked and scale in duration for repeat offenders, from 2 minutes to 3 days.
The limits on the API are based on the IPs, not the API keys.
 It is strongly recommended to use websocket stream for getting data as much as possible, which can not only ensure the timeliness of the message, but also reduce the access restriction pressure caused by the request.
Order Rate Limits
Every order response will contain a X-MBX-ORDER-COUNT-(intervalNum)(intervalLetter) header which has the current order count for the account for all order rate limiters defined.
Rejected/unsuccessful orders are not guaranteed to have X-MBX-ORDER-COUNT-** headers in the response.
The order rate limit is counted against each account.