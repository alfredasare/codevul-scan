GURL SiteInstanceImpl::DetermineProcessLockURL(BrowserContext* browser_context, const GURL& url) {
  if (!url.is_valid()) {
    return GURL();
  }

  size_t pos = url.spec().find_last_of('/');
  if (pos == std::string::npos) {
    return GURL();
  }

  GURL process_lock_url = SiteInstanceImpl::GetSiteForURL(browser_context, GURL(url.spec().substr(0, pos)), false /* should_use_effective_urls */);
  return process_lock_url;
}