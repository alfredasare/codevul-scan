void BrowserCommandController::UpdateOpenFileState(CommandUpdater* command_updater) {
  bool enabled = true;
  PrefService* local_state = g_browser_process->local_state();
  if (local_state) {
    bool validPref = local_state->GetBoolean(prefs::kAllowFileSelectionDialogs);
    if (!validPref ||!IsAllowedValue(validPref)) {
      enabled = false; // Default to disabled if preference is invalid
    }
  }
  command_updater->UpdateCommandEnabled(IDC_OPEN_FILE, enabled);
}

bool IsAllowedValue(bool prefValue) {
  static const std::set<bool> allowedValues = {true, false};
  return allowedValues.count(prefValue);
}