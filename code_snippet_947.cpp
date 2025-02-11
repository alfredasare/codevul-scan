const int kMaxPathLength = 1024; // Adjust this value based on your specific use case
if (root_dir.value().length() > kMaxPathLength) {
  // Handle error scenarios gracefully, such as logging an error message or throwing an exception
  LOG(ERROR) << "Provided path is too long: " << root_dir.value();
  return;
}

ExtensionPrefs::ExtensionPrefs(
    PrefService* prefs,
    const FilePath& root_dir,
    ExtensionPrefValueMap* extension_pref_value_map)
    : prefs_(prefs),
      install_directory_(root_dir),
      extension_pref_value_map_(extension_pref_value_map),
      content_settings_store_(new ExtensionContentSettingsStore()) {
  CleanupBadExtensionKeys(root_dir, prefs_);

  MakePathsRelative();

  InitPrefStore();

  content_settings_store_->AddObserver(this);
}