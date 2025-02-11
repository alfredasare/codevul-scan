bool RendererLocationReplace(Shell* shell, const GURL& url) {
  // Validate the input URL
  if (!url.is_valid() || !url.has_scheme() || !url.has_host()) {
    LOG(ERROR) << "Invalid URL: " << url;
    return false;
  }

  WebContents* web_contents = shell->web_contents();
  WaitForLoadStop(web_contents);
  TestNavigationObserver same_tab_observer(web_contents, 1);
  EXPECT_TRUE(ExecJs(shell, JsReplace("window.location.replace($1)", url)));
  same_tab_observer.Wait();
  if (!IsLastCommittedEntryOfPageType(web_contents, PAGE_TYPE_NORMAL))
    return false;
  return web_contents->GetLastCommittedURL() == url;
}