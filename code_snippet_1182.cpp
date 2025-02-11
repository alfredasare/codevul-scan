bool DebuggerAttachFunction::RunAsync() {
  std::unique_ptr<Attach::Params> params(Attach::Params::Create(*args_));
  EXTENSION_FUNCTION_VALIDATE(params.get());

  // Validate the target debuggee information
  if (!IsValidDebuggeeFormat(params->target)) {
    error_ = ErrorUtils::FormatErrorMessage(
        keys::kInvalidDebuggeeFormatError, params->target);
    return false;
  }

  CopyDebuggee(&debuggee_, params->target);
  if (!InitAgentHost())
    return false;

  //... rest of the code remains the same...
}

bool IsValidDebuggeeFormat(const std::string& target) {
  const std::set<std::string> allowedFormats = {"format1", "format2", "format3"};
  return allowedFormats.find(target)!= allowedFormats.end();
}