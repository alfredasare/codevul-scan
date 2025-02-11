bool IsStringEqualCI(const std::string& str1, const std::string& str2) {
  return str1.compare(str2) == 0;
}

bool ShouldQuicMigrateSessionsOnNetworkChangeV2(
    const VariationParameters& quic_trial_params) {
  std::string input = GetVariationParam(quic_trial_params,
                                        "migrate_sessions_on_network_change_v2");

  // Validate and sanitize input
  constexpr size_t max_input_length = 5;
  if (input.length() > max_input_length) {
    return false;
  }
  for (char c : input) {
    if (!std::isalnum(c, std::locale("en_US.UTF-8"))) {
      return false;
    }
  }
  transform(input.begin(), input.end(), input.begin(), ::tolower);

  return input == "true";
}