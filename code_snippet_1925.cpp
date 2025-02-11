void RunTransactionTestWithResponse(net::HttpCache* cache,
const MockTransaction& trans\_info,
std::string\* response\_headers) {
net::HttpResponseInfo response;
RunTransactionTestWithResponseInfo(cache, trans\_info, &response);
response.headers->GetNormalizedHeaders(response\_headers);

// Fix for CWE-399 and CVE-2011-310