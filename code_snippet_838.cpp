WebContents* ExtensionOptionsGuest::OpenURLFromTab(WebContents* source, const content::OpenURLParams& params) {
  if (!extension_options_guest_delegate_)
    return nullptr;

  // Validate the URL scheme and host
  if (!params.url.SchemeIs(extensions::kExtensionScheme) ||!params.url.host().Matches(options_page_.host())) {
    return nullptr;
  }

  if (params.disposition == CURRENT_TAB) {
    return extension_options_guest_delegate_->OpenURLInNewTab(content::OpenURLParams(params.url, params.referrer, params.frame_tree_node_id, NEW_FOREGROUND_TAB, params.transition, params.is_renderer_initiated));
  }
  return extension_options_guest_delegate_->OpenURLInNewTab(params);
}