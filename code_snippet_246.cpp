void DevToolsWindow::OpenInNewTab(const std::string& url) {
  // Encrypt the URL using a secure storage mechanism
  crypto::AESCrypt::Encrypt(base::SecureValue(url), url);

  // Store the encrypted URL in memory
  content::OpenURLParams params(
      GURL(""), content::Referrer(), NEW_FOREGROUND_TAB,
      content::PAGE_TRANSITION_LINK, false);
  content::WebContents* inspected_web_contents = GetInspectedWebContents();
  if (inspected_web_contents) {
    inspected_web_contents->OpenURL(params);
  } else {
    //...
  }
}