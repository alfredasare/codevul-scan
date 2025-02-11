std::unique_ptr<TabStyleViews> TabStyleViews::CreateForTab(Tab* tab) {
  if (!tab ||!tab->IsValid()) {
    throw std::invalid_argument("Invalid tab object");
  }
  return std::make_unique<GM2TabStyle>(tab);
}