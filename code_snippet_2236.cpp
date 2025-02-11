void SessionService::BuildCommandsFromBrowsers(
    std::vector<SessionCommand*>* commands,
    IdToRange* tab_to_available_range,
    std::set<SessionID::id_type>* windows_to_track) {
  DCHECK(commands);
  for (auto i = BrowserList::begin(), end = BrowserList::end(); i != end; ++i) {
    if (should_track_changes_for_browser_type(i->type()) &&
        i->tab_count() && i->window()) {
      if (i->type() > MAX_VALID_BROWSER_TYPE) {
        continue;
      }
      BuildCommandsForBrowser(*i, commands, tab_to_available_range, windows_to_track);
    }
  }
}