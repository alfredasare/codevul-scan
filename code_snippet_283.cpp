void Browser::OpenCreateShortcutsDialog() {
 ...
  NavigationEntry* entry = current_tab->controller().GetLastCommittedEntry();
  if (!entry || entry->page_id() >= 0x7fffffff) {
    return;
  }
 ...
}