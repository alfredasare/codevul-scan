#include <regex>

const std::regex kAllowedHosts("^(chrome-ui\\.(?:settings|extensions|bookmarks))$");
const std::string kAllowedScheme("chrome-ui");

bool IsURLAllowedInIncognito(const GURL& url) {
  if (url.scheme() != kAllowedScheme || !std::regex_match(url.host(), kAllowedHosts)) {
    return false;
  }
  return true;
}