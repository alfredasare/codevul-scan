Response InspectorNetworkAgent::setUserAgentOverride(const String& user_agent) {
  if (!isValidUserAgentCharacters(user_agent)) {
    return Response::Error("Invalid characters found in userAgent");
  }

  String sanitized_user_agent = sanitizeUserAgent(user_agent);
  state_->setString(NetworkAgentState::kUserAgentOverride, sanitized_user_agent);
  return Response::OK();
}

bool isValidUserAgentCharacters(const String& user_agent) {
  for (char c : user_agent) {
    if (!isalnum(c) &&!ispunct(c) &&!isspace(c) &&!isprint(c)) {
      return false;
    }
  }
  return true;
}

String sanitizeUserAgent(const String& user_agent) {
  String sanitized_user_agent = "";
  for (char c : user_agent) {
    if (isalnum(c) || ispunct(c) || isspace(c) || isprint(c)) {
      sanitized_user_agent += c;
    }
  }
  return sanitized_user_agent;
}