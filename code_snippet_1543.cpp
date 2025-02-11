static bool IsDangerousHTTPEquiv(const String& value) {
  String sanitizedValue = SanitizeInput(value);
  String equiv = sanitizedValue.StripWhiteSpace();
  return DeprecatedEqualIgnoringCase(equiv, "refresh") || 
         DeprecatedEqualIgnoringCase(equiv, "set-cookie");
}

String SanitizeInput(const String& input) {
  const String allowedChars = "[a-zA-Z0-9_\\-. ]";
  String sanitized = "";
  for (char c : input) {
    if (RegexMatch(allowedChars, c)) {
      sanitized += c;
    } else {
      sanitized += HtmlEscape(c);
    }
  }
  return sanitized;
}