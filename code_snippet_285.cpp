void Browser::OpenCreateShortcutsDialog() {
 UserMetrics::RecordAction(UserMetricsAction("CreateShortcut"), profile_);
#if defined(OS_WIN) || defined(OS_LINUX)
TabContentsWrapper* current_tab = GetSelectedTabContentsWrapper();
if (current_tab && web_app::IsValidUrl(current_tab->tab\_contents()->GetURL())) {
NavigationEntry* entry = current_tab->controller().GetLastCommittedEntry();
if (entry) {
pending\_web\_app\_action\_ = CREATE\_SHORTCUT;
current\_tab->render\_view\_host()->GetApplicationInfo(entry->page\_id());
}
}
#else
NOTIMPLEMENTED();
#endif
}