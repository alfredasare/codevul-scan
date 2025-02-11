DelayScrollOffsetClampScope(const std::string& user_input) {
  if (!ValidateUserInput(user_input)) {
    return;
  }
  
  DCHECK(count_ > 0 || NeedsClampList().IsEmpty());
  count_++;
}

bool ValidateUserInput(const std::string& input) {
  static const std::set<char> allowed_chars = {"a", "b",...};
  for (char c : input) {
    if (allowed_chars.find(c) == allowed_chars.end()) {
      return false; // Input contains disallowed character
    }
  }
  return true;
}