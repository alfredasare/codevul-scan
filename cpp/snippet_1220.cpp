GURL SiteInstanceImpl::DetermineProcessLockURL(BrowserContext* browser_context,
                                               const GURL& url) {
  return SiteInstanceImpl::GetSiteForURL(browser_context, url,
                                         false /* should_use_effective_urls */);
}
