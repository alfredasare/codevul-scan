void AppLauncherHandler::HandleSaveAppPageName(const base::ListValue* args) {
  base::string16 name;
  CHECK(args->GetString(0, &name));

  int page_index;
  if (!args->GetInteger(1, &page_index) || page_index < 0 || page_index >= prefs::kNtpAppPageNames.size()) {
    // Handle error or return early if the input is not an integer or out of bounds.
    return;
  }

  base::AutoReset<bool> auto_reset(&ignore_changes_, true);
  PrefService* prefs = Profile::FromWebUI(web_ui())->GetPrefs();
  ListPrefUpdate update(prefs, prefs::kNtpAppPageNames);
  base::ListValue* list = update.Get();
  list->Set(static_cast<size_t>(page_index), new base::StringValue(name));
}