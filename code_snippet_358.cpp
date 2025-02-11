c++
void CastConfigDelegateChromeos::GetReceiversAndActivities(
    const ReceiversAndActivitesCallback& callback) {
  std::string userInput = "backgroundSetup.getMirrorCapableReceiversAndActivities();";
  userInput = SanitizeInput(userInput);
  ExecuteJavaScriptWithCallback(userInput, base::Bind(&GetReceiversAndActivitiesCallback, callback));
}

std::string SanitizeInput(const std::string& input) {
  static const std::set<char> allowedChars = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_.$"};
  std::string sanitizedInput;
  for (char c : input) {
    if (allowedChars.find(c)!= allowedChars.end()) {
      sanitizedInput += c;
    }
  }
  return sanitizedInput;
}