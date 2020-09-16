Endpoint Security Type
Each endpoint has a security type that determines the how you will interact with it.
API-keys are passed into the Rest API via the X-MBX-APIKEY header.
API-keys and secret-keys are case sensitive.
API-keys can be configured to only access certain types of secure endpoints. For example, one API-key could be used for TRADE only, while another API-key can access everything except for TRADE routes.
By default, API-keys can access all secure routes.
Security Type	Description

NONE	Endpoint can be accessed freely.
TRADE	Endpoint requires sending a valid API-Key and signature.
USER_DATA	Endpoint requires sending a valid API-Key and signature.
USER_STREAM	Endpoint requires sending a valid API-Key.
MARKET_DATA	Endpoint requires sending a valid API-Key.
TRADE and USER_DATA endpoints are SIGNED endpoints.