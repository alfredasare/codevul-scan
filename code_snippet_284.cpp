c++
void CreateShortcutsInApplicationsMenu(Profile* profile,
                                       const Extension* app) {
  // Limit the number of characters in the app ID to prevent path traversal
  const std::string& app_id = app->id();
  const int kMaxAppIdLength = 32;
  if (app_id.length() > kMaxAppIdLength) {
    app_id = app_id.substr(0, kMaxAppIdLength);
  }

  web_app::ShortcutLocations creation_locations;
  creation_locations.applications_menu_location =
      web_app::APP_MENU_LOCATION_SUBDIR_CHROMEAPPS + app_id;
  web_app::CreateShortcuts(
      web_app::SHORTCUT_CREATION_AUTOMATED, creation_locations, profile, app);
}