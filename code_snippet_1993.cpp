size_t IndexOf(const std::vector<std::string>& warnings, const std::string& warning) {
  for (size_t i = 0; i < warnings.size(); ++i) {
    if (warnings[i] == warning)
      return i;
  }

  return warnings.size();
}