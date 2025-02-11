void DocumentLoader::AppendRedirect(const KURL& url) {
  // Validate the input URL
  if (!IsTrustedDomain(url)) {
    return;
  }

  // Whitelist approach to validate the URL
  if (!url.protocolIsInList({"http", "https"}) ||
    !url.domainIsInList({"trusteddomain1.com", "trusteddomain2.com"}) ||
    !url.pathMatchesPattern("/allowed/path/*")) {
    return;
  }

  redirect_chain_.push_back(url);
}