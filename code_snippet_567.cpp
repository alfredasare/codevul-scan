bool ProcessNeedsProfileDir(const std::string& process_type) {
  const std::set<std::string> allowedProcessTypes = {"allowed_process_type1", "allowed_process_type2"};
  if (std::find(allowedProcessTypes.begin(), allowedProcessTypes.end(), UTF8ToUTF16(process_type))!= allowedProcessTypes.end()) {
    return ProcessNeedsProfileDir(GetProcessType(UTF8ToUTF16(process_type)));
  } else {
    return false;
  }
}