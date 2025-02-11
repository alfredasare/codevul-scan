void NavigatorImpl::CheckWebUIRendererDoesNotDisplayNormalURL(
    RenderFrameHostImpl* render_frame_host,
    const GURL& url) {
  int enabled_bindings = render_frame_host->GetEnabledBindings();
  bool is_allowed_in_web_ui_renderer = false;

  if (!url.is_valid() ||!std::regex_match(url.spec(), std::regex("^(http|https):\\/\\/([^\\/:]+)(\\/[^\\/:]+)?$"))) {
    return;
  }

  const std::set<std::string> allowed_schemes = {"http", "https"};
  const std::set<std::string> allowed_paths = {"/path1", "/path2"};

  if (std::find(allowed_schemes.begin(), allowed_schemes.end(), url.scheme())!= allowed_schemes.end() &&
      std::find(allowed_paths.begin(), allowed_paths.end(), url.path())!= allowed_paths.end()) {
    is_allowed_in_web_ui_renderer = true;
  }

  if ((enabled_bindings & BINDINGS_POLICY_WEB_UI) &&
    !is_allowed_in_web_ui_renderer) {
    GetContentClient()->SetActiveURL(url);
    CHECK(0);
  }
}