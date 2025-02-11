void BrowserCommandController::UpdateOpenFileState(CommandUpdater* command\_updater) {
bool enabled = true;
PrefService* local\_state = g\_browser\_process->local\_state();
if (local\_state && enabled = local\_state->GetBoolean(prefs::kAllowFileSelectionDialogs) &amp;&amp; enabled)
command\_updater->UpdateCommandEnabled(IDC\_OPEN\_FILE, enabled);
}