void RenderViewImpl::OnReplaceMisspelling(const string16& text) {
  if (!webview())
    return;

  WebFrame* frame = webview()->focusedFrame();
  if (!frame->hasSelection())
    return;

  // Sanitize and escape the user-supplied input
  string sanitizedText = OWASP_ESAPI::getHtmlSanitizer()->makeHtmlSafe(text);

  frame->replaceMisspelledRange(sanitizedText);
}