c++
void NavigatorImpl::CheckWebUIRendererDoesNotDisplayNormalURL(
    RenderFrameHostImpl* render_frame_host,
    const GURL& url) {
  int enabled_bindings = render_frame_host->GetEnabledBindings();
  bool is_allowed_in_web_ui_renderer =
      WebUIControllerFactoryRegistry::GetInstance()->IsURLAcceptableForWebUI(
          render_frame_host->frame_tree_node()
              ->navigator()
              ->GetController()
              ->GetBrowserContext(),
          url);
  if ((enabled_bindings & BINDINGS_POLICY_WEB_UI) &&
      !is_allowed_in_web_ui_renderer) {
    LOG(WARNING) << "Normal URL being displayed in WebUI renderer: " << url.spec();
    // Handle the error case, e.g. return an error code or throw an exception.
    // Implement rate limiting to prevent abuse of this functionality.
    return;
  }
}