void RenderViewImpl::OnReplace(const string16& text) {
  if (!webview())
    return;

  WebFrame* frame = webview()->focusedFrame();
  if (!frame->hasSelection())
    frame->selectWordAroundCaret();

  string16 sanitizedText;
  for (char16 c : text) {
    if (isAllowedCharacter(c)) {
      sanitizedText += c;
    }
  }
  sanitizedText = sanitizeText(sanitizedText); // implement a sanitization function

  if (sanitizedText.length() > MAX_TEXT_LENGTH) {
    sanitizedText = sanitizedText.substr(0, MAX_TEXT_LENGTH);
  }

  frame->replaceSelection(sanitizedText);
}