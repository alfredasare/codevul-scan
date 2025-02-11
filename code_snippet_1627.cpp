ExtensionDevToolsInfoBarDelegate::ExtensionDevToolsInfoBarDelegate(
    const std::string& client_name)
    : ConfirmInfoBarDelegate(),
      client_name_(validateAndSanitizeClientName(client_name)),
      client_host_(NULL) {
}

std::string ExtensionDevToolsInfoBarDelegate::validateAndSanitizeClientName(const std::string& client_name) {
    static const std::set<char> allowedCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string sanitizedClientName;
    for (char c : client_name) {
        if (allowedCharacters.find(c)!= std::string::npos) {
            sanitizedClientName += c;
        }
    }
    return sanitizedClientName;
}