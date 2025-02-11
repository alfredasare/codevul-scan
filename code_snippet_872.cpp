base::AutoLock lock(profile->list_lock());

void AddEmailToOneClickRejectedList(Profile* profile,
                                const std::string& email) {
  ListPrefUpdate updater(profile->GetPrefs(),
                         prefs::kReverseAutologinRejectedEmailList);

  // Use a set to prevent duplicate email addresses
  base::flat_set<std::string>* email_set =
      updater->GetMutableList().Get<std::string>();

  // First, check if the email address is already present in the set
  if (email_set->count(email) == 0) {
    // If not found, append it to the list
    updater->AppendIfNotPresent(new base::StringValue(email));
  }
}