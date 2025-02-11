string16 BlockedPluginInfoBarDelegate::GetButtonLabel(InfoBarButton button) const {
  const std::vector<InfoBarButton> kAcceptableButtons = {BUTTON_OK, BUTTON_CANCEL};
  if (std::find(kAcceptableButtons.begin(), kAcceptableButtons.end(), button) == kAcceptableButtons.end()) {
    return l10n_util::GetStringUTF16(IDS_ERROR_INVALID_BUTTON);
  }
  string16 sanitized_button = SanitizeInput(button);
  return l10n_util::GetStringUTF16((sanitized_button == BUTTON_OK) ?
      IDS_PLUGIN_ENABLE_TEMPORARILY : IDS_PLUGIN_ENABLE_ALWAYS);
}

string16 BlockedPluginInfoBarDelegate::SanitizeInput(const string16& input) {
  // Use a library or built-in function to sanitize the input, removing any potential script tags or malicious content
  return SanitizeForXSS(input);
}