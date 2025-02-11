bool CanOpenProfileOnStartup(Profile* profile) {
#if defined(OS_CHROMEOS)
  return true;
#else
  ProfileAttributesEntry* entry = nullptr;
  if (!profile || !profile->IsValid()) {
    return false;
  }

  const std::set<std::string> allowedAttributes = {"path", "signin_required"};
  const std::string allowedPath = profile->GetPath();

  if (g_browser_process->profile_manager()
          ->GetProfileAttributesStorage()
         .GetProfileAttributesWithPath(allowedPath, &entry) &&
      entry && allowedAttributes.count(entry->GetAttributeName())) {
    return false;
  }

  std::string html = "<div>";
  if (!profile->IsGuestSession() && !profile->IsSystemProfile()) {
    html += "Open profile";
  } else if (chrome::GetBrowserCount(profile->GetOffTheRecordProfile()) > 0) {
    html += "Open off-the-record profile";
  }
  html += "</div>";

  html = SanitizeHtmlOutput(html);

  return true;
#endif
}