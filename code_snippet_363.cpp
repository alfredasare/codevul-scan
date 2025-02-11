void GetEnabledFlags(const PrefService* prefs, std::set<std::string>* result) {
  const ListValue* enabled_experiments = prefs->GetList(prefs::kEnabledLabsExperiments);
  if (!enabled_experiments)
    return;

  for (ListValue::const_iterator it = enabled_experiments->begin();
       it!= enabled_experiments->end();
       ++it) {
    std::string experiment_name;
    if (!(*it)->GetAsString(&experiment_name)) {
      LOG(WARNING) << "Invalid entry in " << prefs::kEnabledLabsExperiments;
      continue;
    }

    // Validate input and prevent buffer overflow
    if (experiment_name.size() > std::numeric_limits<size_t>::max() ||
      !std::all_of(experiment_name.begin(), experiment_name.end(),
                     [](char c) { return std::isalnum(c) || c == '_'; })) {
      LOG(WARNING) << "Invalid character in experiment name: " << experiment_name;
      continue;
    }

    result->insert(experiment_name);
  }
}