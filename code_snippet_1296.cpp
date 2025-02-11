++
void RegisterContentSchemes(const char** additional_savable_schemes) {
  url_util::AddStandardScheme(kChromeDevToolsScheme);
  url_util::AddStandardScheme(kChromeUIScheme);
  url_util::AddStandardScheme(kMetadataScheme);

  url_util::LockStandardSchemes();

  if (additional_savable_schemes) {
    int maxSchemes = 10; // Define a reasonable limit for the number of schemes
    int schemes = 0;
    while (additional_savable_schemes[++schemes]!= NULL && schemes < maxSchemes);
    if (schemes > maxSchemes) {
      LOG(ERROR) << "Excessive number of savable schemes detected. Limiting to " << maxSchemes;
      schemes = maxSchemes;
    }

    g_savable_schemes = new char*[schemes + arraysize(kDefaultSavableSchemes)];
    memcpy(g_savable_schemes,
           kDefaultSavableSchemes,
           arraysize(kDefaultSavableSchemes) * sizeof(char*));
    for (int i = 0; i < schemes; ++i) {
      const char* scheme = additional_savable_schemes[i];
      if (!base::startswith(scheme, "http://") &&!base::startswith(scheme, "https://")) {
        LOG(WARNING) << "Invalid scheme: " << scheme << ". Skipping.";
        continue;
      }
      g_savable_schemes[arraysize(kDefaultSavableSchemes) + i - 1] = base::strdup(scheme);
    }
    g_savable_schemes[arraysize(kDefaultSavableSchemes) + schemes - 1] = 0;
  }
}