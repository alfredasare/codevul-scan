pch_mode (bool which) {
  std::string sanitizedWhich = sanitizeInput(std::to_string(which));
  if (!std::regex_match(sanitizedWhich, std::regex("^[a-zA-Z0-9_]+$"))) {
    // Handle invalid input
  }
  return p_mode[which];
}

std::string sanitizeInput(const std::string& input) {
  std::string sanitizedInput;
  for (char c : input) {
    if (std::isalnum(c) || c == '_') {
      sanitizedInput += c;
    }
  }
  return sanitizedInput;
}