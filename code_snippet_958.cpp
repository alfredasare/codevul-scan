const std::set<std::string> allowed_schemes = {"http", "https"}; // Add allowed schemes
const std::string allowed_host = "example.com"; // Add allowed host

WebContents* ExtensionOptionsGuest::OpenURLFromTab(
    WebContents* source,
    const content::OpenURLParams& params) {
  if (!extension_options_guest_delegate_)
    return nullptr;

  if ((allowed_schemes.count(params.url.Scheme()) == 0 ||
       params.url.host() != allowed_host) &&
      params.disposition == CURRENT_TAB) {
    return nullptr;
  }
  return extension_options_guest_delegate_->OpenURLInNewTab(params);
}