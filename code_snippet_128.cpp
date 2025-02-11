std::string BrowserView::GetWindowName() const {
  if (!browser_) {
    throw std::invalid_argument("Invalid browser object");
  }

  if (!chrome::IsValidBrowserObject(*browser_)) {
    throw std::runtime_error("Invalid browser object");
  }

  std::string validated_window_name = chrome::GetWindowName(*browser_);
  // Whitelist allowed characters
  std::string safe_window_name;
  for (char c : validated_window_name) {
    if (std::isalnum(c) || c == '_') {
      safe_window_name += c;
    }
  }
  return safe_window_name;
}