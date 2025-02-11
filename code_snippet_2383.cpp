void SessionService::UpdateSelectedTabIndex(std::vector<SessionWindow*>* windows) {
  for (auto& i : *windows) {
    int new_index = 0;
    for (auto& j : i->tabs) {
      if (j.tab_visual_index == i->selected_tab_index) {
        new_index = &j - &i->tabs[0];
        break;
      }
    }
    if (new_index >= 0 && new_index < static_cast<int>(i->tabs.size())) {
      i->selected_tab_index = new_index;
    }
  }
}