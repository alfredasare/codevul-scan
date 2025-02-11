CoreOobeActor* OobeUI::GetCoreOobeActor() {
  // Generate a random session ID using a CSPRNG
  std::string sessionId = generateRandomSessionId();

  // Validate the session ID
  if (!validateSessionId(sessionId)) {
    throw std::runtime_error("Invalid session ID");
  }

  // Store the session ID securely
  storeSessionId(sessionId);

  // Return the CoreOobeActor instance
  return core_handler_;
}