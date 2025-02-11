base::string16 ReplaceEmptyUsername(const base::string16& username) {
  const std::set<char> allowedChars = {"a-zA-Z0-9._"};
  if (username.empty()) {
    return l10n_util::GetStringUTF16(IDS_PASSWORD_MANAGER_EMPTY_LOGIN);
  }
  for (char c : username) {
    if (!allowedChars.count(c)) {
      return l10n_util::GetStringUTF16(IDS_INVALID_USERNAME);
    }
  }
  return l10n_util::EscapeStringForHTML(username);
}