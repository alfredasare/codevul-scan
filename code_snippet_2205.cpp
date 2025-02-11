c++
void SafeBrowsingBlockingPage::SetReportingPreference(bool report) {
  Profile* profile = Profile::FromBrowserContext(
      web_contents_->GetBrowserContext());
  PrefService* pref = profile->GetPrefs();

  // Validate the input
  if (!std::is_same<bool>(report)) {
    LOG(ERROR) << "Invalid input type";
    return;
  }

  // Use a safe string formatting method
  pref->SetBool(prefs::kSafeBrowsingReportingEnabled, report);
}