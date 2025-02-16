c++
bool CanOpenProfileOnStartup(Profile* profile) {
#if defined(OS_CHROMEOS)
  return true;
#else
  ProfileAttributesEntry entry;
  if (g_browser_process->profile_manager()
          ->GetProfileAttributesStorage()
          .GetProfileAttributes(profile->GetPath(), &entry) &&
      entry.IsSigninRequired()) {
    return false;
  }

  return (!profile->IsGuestSession() && !profile->IsSystemProfile()) ||
         (chrome::GetBrowserCount(profile->GetOffTheRecordProfile()) > 0);
#endif
}