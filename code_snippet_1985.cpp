content::WebContents* ExtensionTabsZoomTest::OpenUrlAndWaitForLoad(const GURL& url) {
  // Validate the input URL
  if (!url.is_valid() ||!url.is_scheme_supported()) {
    LOG(ERROR) << "Invalid URL: " << url;
    return nullptr;
  }

  ui_test_utils::NavigateToURLWithDisposition(
      browser(), url, WindowOpenDisposition::NEW_FOREGROUND_TAB,
      ui_test_utils::BROWSER_TEST_WAIT_FOR_NAVIGATION);
  return browser()->tab_strip_model()->GetActiveWebContents();
}