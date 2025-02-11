void DocumentModuleScriptFetcher::Finalize(
    const WTF::Optional<ModuleScriptCreationParams>& params,
    const HeapVector<Member<ConsoleMessage>>& error_messages) {
  NotifyFetchFinished(params, error_messages);

  // Example: Handle errors in a way that does not expose sensitive information
  for (auto& error_message : error_messages) {
    if (error_message->hasError()) {
      std::string sanitizedErrorMessage = sanitizeErrorString(error_message->errorMessage());
      ConsoleLog::AddText(sanitizedErrorMessage);
    }
  }
}

std::string sanitizeErrorString(const String& errorMessage) {
  // Implement a mechanism to securely remove sensitive information from the error message
  return errorMessage.replace("API_KEY", "").replace("SECRET_TOKEN", "");
}