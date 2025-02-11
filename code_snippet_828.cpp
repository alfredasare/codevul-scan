ExtensionPrefs::ExtensionPrefs(
    PrefService* prefs,
    const FilePath& root_dir,
    ExtensionPrefValueMap* extension_pref_value_map)
    : prefs_(prefs),
      install_directory_(FilePath::Normalize(root_dir)),
      extension_pref_value_map_(extension_pref_value_map),
      content_settings_store_(new ExtensionContentSettingsStore()) {
  if (!FilePath::IsValidPath(install_directory_)) {
    // Handle invalid root directory
  }

  CleanupBadExtensionKeys(install_directory_, prefs_);

  MakePathsRelative();

  InitPrefStore();

  content_settings_store_->AddObserver(this);
}