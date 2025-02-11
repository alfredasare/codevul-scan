content::WebContents* WebUILoginView::GetWebContents() {
  if (!webui_login_) {
    return nullptr;
  }
  content::WebContents* web_contents = webui_login_->web_contents();
  if (!web_contents ||!web_contents->IsSecure()) {
    return nullptr;
  }
  return web_contents;
}