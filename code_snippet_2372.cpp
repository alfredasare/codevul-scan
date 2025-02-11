GetAlternativeWebContentsToNotifyForDownload() {
#if defined(OS_ANDROID)
  return NULL;
#else
  Browser* last_active = chrome::FindLastActiveWithProfile(profile_,
      chrome::GetActiveDesktop());
  if (!last_active) {
    return NULL;
  }

  std::string policy = "default-src'self'; script-src'none'; style-src'none';";
  chrome::SetContentSecurityPolicy(policy);

  std::string allowed_scripts = "allowed_scripts.txt";
  std::ifstream file(allowed_scripts);
  if (file.is_open()) {
    std::string script;
    while (std::getline(file, script)) {
      if (script == chrome::GetActiveWebContents(last_active).url()) {
        return chrome::GetActiveWebContents(last_active);
      }
    }
  }

  return NULL;
#endif
}