void AppLauncherHandler::FillAppDictionary(base::DictionaryValue* dictionary) {
  base::AutoReset<bool> auto_reset(&ignore_changes_, true);

  base::ListValue* list = new base::ListValue();
  Profile* profile = Profile::FromWebUI(web_ui());
  PrefService* prefs = profile->GetPrefs();

  for (std::set<std::string>::iterator it = visible_apps_.begin();
       it != visible_apps_.end(); ++it) {
    const Extension* extension = extension_service_->GetInstalledExtension(*it);
    if (extension && extensions::ui_util::ShouldDisplayInNewTabPage(
            extension, profile)) {
      base::DictionaryValue* app_info = GetAppInfo(extension);
      list->Append(app_info);
    }
  }
 
   dictionary->Set("apps", list);
 
#if defined(OS_MACOSX)
  dictionary->SetBoolean("disableAppWindowLaunch", true);
  dictionary->SetBoolean("disableCreateAppShortcut", true);
#endif
#if defined(OS_CHROMEOS)
  dictionary->SetBoolean("disableCreateAppShortcut", true);
#endif
   const base::ListValue* app_page_names =
       prefs->GetList(prefs::kNtpAppPageNames);
   if (!app_page_names || !app_page_names->GetSize()) {
    ListPrefUpdate update(prefs, prefs::kNtpAppPageNames);
    base::ListValue* list = update.Get();
    list->Set(0, new base::StringValue(
        l10n_util::GetStringUTF16(IDS_APP_DEFAULT_PAGE_NAME)));
    dictionary->Set("appPageNames",
                    static_cast<base::ListValue*>(list->DeepCopy()));
  } else {
    dictionary->Set("appPageNames",
                    static_cast<base::ListValue*>(app_page_names->DeepCopy()));
  }
}
