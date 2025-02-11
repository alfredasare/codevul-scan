void GetEnabledFlags(const PrefService* prefs, std::set<std::string>* result) {
  const ListValue* enabled_experiments = prefs->GetList(prefs::kEnabledLabsExperiments);
  if (!enabled_experiments) return;

  constexpr size_t kMaxExperimentNameLength = 64;
  const std::string kAllowedChars = "abcdefghijklmnopqrstuvwxyz"
                                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                    "0123456789_-";

  for (ListValue::const_iterator it = enabled_experiments->begin();
       it != enabled_experiments->end();
       ++it) {
    std::string experiment_name;
    if (!(*it)->GetAsString(&experiment_name)) {
      LOG(WARNING) << "Invalid entry in " << prefs::kEnabledLabsExperiments;
      continue;
    }

    if (experiment_name.length() > kMaxExperimentNameLength ||
        !std::all_of(experiment_name.begin(), experiment_name.end(),
                     [&kAllowedChars](char c) { return kAllowedChars.find(c) != std::string::npos; })) {
      LOG(WARNING) << "Experiment name contains disallowed characters or is too long: " << experiment_name;
      continue;
    }

    result->insert(experiment_name);
  }
}