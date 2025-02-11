Response InspectorNetworkAgent::setUserAgentOverride(const String& user_agent) {
 String sanitized_user_agent = user\_agent.SanitizeForHTML();
 if (sanitized_user_agent.Contains(‘\n’) || sanitized_user_agent.Contains(‘\r’) ||
 sanitized_user_agent.Contains(‘\0’)) {
 return Response::Error("Invalid characters found in userAgent");
 }
 state_->setString(NetworkAgentState::kUserAgentOverride, sanitized_user_agent);
 return Response::OK();
}