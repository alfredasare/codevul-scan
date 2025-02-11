#include <regex>

bool IsSafeForHTML(const string16& text) {
  static const std::regex kSafeHTML("^[a-zA-Z0-9\\s!@#$%^&*(),.?:\"'`~/\\-]+$");
  return std::regex_match(text, kSafeHTML);
}

void RenderViewImpl::OnReplace(const string16& text) {
  if (!webview())
    return;

  if (IsSafeForHTML(text)) {
    WebFrame* frame = webview()->focusedFrame();
    if (!frame->hasSelection())
      frame->selectWordAroundCaret();

    frame->replaceSelection(text);
  } else {
    // Log the error, reject the input, or handle it as appropriate for your application.
  }
}