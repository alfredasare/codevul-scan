`std::string BrowserView::GetWindowName() const {
  return chrome::GetWindowName(const_cast<Browser*>(browser_).get());
}`