// Add the following helper function to your codebase.
bool IsSafeCommand(const WebString& command) {
  static const char* const safeCommands[] = {"Cut", "Copy", "Paste"};
  for (const auto& safeCommand : safeCommands) {
    if (command == WebString::fromUTF8(safeCommand)) {
      return true;
    }
  }
  return false;
}

// Modify the RenderFrameImpl::OnCut function as shown below.
void RenderFrameImpl::OnCut() {
  base::AutoReset<bool> handling_select_range(&handling_select_range_, true);

  // Sanitize the command using the helper function.
  if (IsSafeCommand(WebString::fromUTF8("Cut"))) {
    frame_->executeCommand(WebString::fromUTF8("Cut"), GetFocusedElement());
  }
}