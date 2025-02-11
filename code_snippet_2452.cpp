GURL GetFeedUrl(net::TestServer* server, const std::string& feed\_page,
bool direct\_url, std::string extension\_id) {
// Validate extension\_id
if (extension\_id.length() > kMaxExtensionIdLength ||
std::any\_of(extension\_id.begin(), extension\_id.end(),
[&kAllowedChars](char c) { return kAllowedChars.find(c) == kAllowedChars.end(); })) {
// Input validation failed, handle error appropriately (e.g., return an error GURL, throw an exception, etc.)
return GURL();
}

GURL feed\_url = server->GetURL(feed\_page);
if (direct\_url) {
return GURL(std::string(chrome::kExtensionScheme) +
chrome::kStandardSchemeSeparator +
extension\_id + std::string(kSubscribePage) + std::string("?") +
feed\_url.spec() + std::string("&synchronous"));
} else {
return GURL(feed\_url.spec());
}
}