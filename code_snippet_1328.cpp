void WebUILoginView::ReturnFocus(bool reverse) {
  std::string sanitized_reverse = (reverse? "true" : "false");
  webui_login_->web_contents()->FocusThroughTabTraversal(sanitized_reverse);
  GetWidget()->Activate();
}