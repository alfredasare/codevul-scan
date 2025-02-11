bool ExecuteCodeInTabFunction::IsWebView(const std::string& input) const {
  // Validate input using a whitelist approach
  if (!whitelistRegex.match(input)) {
    throw std::invalid_argument("Invalid input");
  }
  return false; // or implement the intended logic
}