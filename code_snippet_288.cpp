void RenderFrameImpl::OnCut() {
  base::AutoReset<bool> handling_select_range(&handling_select_range_, true);
  std::string command = WebString::fromUTF8("Cut");
  command = SanitizeCommandString(command);
  frame_->executeCommand(command, GetFocusedElement());
}

std::string SanitizeCommandString(const std::string& input) {
  static const std::set<std::string> allowed_commands = {"Cut", "Copy", "Paste"};
  std::string sanitized_command;
  for (char c : input) {
    if (allowed_commands.find(std::string(1, c))!= allowed_commands.end()) {
      sanitized_command += c;
    }
  }
  return sanitized_command;
}