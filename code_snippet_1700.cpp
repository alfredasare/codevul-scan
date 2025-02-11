bool IsURLAllowedInIncognito(const GURL& url) {
  if (!url.is_valid()) {
    return false;
  }
  if (url.scheme()!= chrome::kChromeUIScheme) {
    return false;
  }
  std::set<std::string> allowedHosts = {"chrome-ui-settings", "chrome-ui-extensions", "chrome-ui-bookmarks"};
  if (std::find(allowedHosts.begin(), allowedHosts.end(), url.host()) == allowedHosts.end()) {
    return false;
  }
  return true;
}