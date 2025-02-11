void RestoreForeignSession(
    std::vector<const SessionWindow*>::const_iterator begin,
    std::vector<const SessionWindow*>::const_iterator end) {
  StartTabCreation();
  for (std::vector<const SessionWindow*>::const_iterator i = begin;
       i!= end; ++i) {
    Browser* browser = CreateRestoredBrowser(
        GetValidBrowserType((*i)->type), 
        SanitizeBounds((*i)->bounds), 
        (*i)->show_state);

    const int initial_tab_count = browser->tab_count();
    int selected_tab_index = (*i)->selected_tab_index;
    RestoreTabsToBrowser(*(*i), browser, selected_tab_index);
    ShowBrowser(browser, initial_tab_count, selected_tab_index);
    tab_loader_->TabIsLoading(
        &browser->GetSelectedWebContents()->GetController());
    NotifySessionServiceOfRestoredTabs(browser, initial_tab_count);
  }

  FinishedTabCreation(true, true);
}

Browser::Type GetValidBrowserType(const std::string& type) {
  // Map string type to valid Browser::Type value
  // or throw an exception if invalid
  static const std::map<std::string, Browser::Type> typeMap = {
    {"chrome", Browser::Type::CHROME},
    {"firefox", Browser::Type::FIREFOX},
    // Add more mappings as needed
  };
  auto it = typeMap.find(type);
  if (it == typeMap.end()) {
    throw std::invalid_argument("Invalid browser type");
  }
  return it->second;
}

std::string SanitizeBounds(const std::string& bounds) {
  // Remove any malicious characters from the bounds string
  std::string sanitizedBounds;
  for (char c : bounds) {
    if (isalnum(c) || c == '/') {
      sanitizedBounds += c;
    }
  }
  return sanitizedBounds;
}