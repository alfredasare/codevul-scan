void SessionService::UpdateSelectedTabIndex(std::vector<SessionWindow*>* windows) {
  if (!windows || windows->empty()) {
    return; // invalid input, exit early
  }

  for (std::vector<SessionWindow*>::const_iterator i = windows->begin();
       i != windows->end(); ++i) {
    SessionWindow* window = *i; // secure copy
    if (!window || !window->tabs) {
      continue; // invalid window, skip
    }

    int new_index = 0;
    for (std::vector<SessionTab*>::const_iterator j = window->tabs.begin();
         j != window->tabs.end(); ++j) {
      SessionTab* tab = *j; // secure copy
      if (!tab || tab->tab_visual_index < 0) {
        continue; // invalid tab, skip
      }

      if (tab->tab_visual_index == window->selected_tab_index) {
        new_index = static_cast<int>(j - window->tabs.begin());
        break;
      }
    }
    window->selected_tab_index = new_index;
  }
}