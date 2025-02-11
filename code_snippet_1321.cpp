bool EnableInProcessStackDumpingForSandbox() {
  if (USE_SYMBOLIZE) {
    std::string sanitizedInput = SandboxSymbolizeHelper::GetInstance()->sanitizeInput();
    if (isValidInput(sanitizedInput)) {
      return EnableInProcessStackDumping();
    }
  }
  return false;
}

bool isValidInput(const std::string& input) {
  return!input.find("<script>") &&!input.find("<");
}