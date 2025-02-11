static bool IsDangerousHTTPEquiv(const String& value) {
  String equiv = value.StripWhiteSpace();
  return equiv.Equals("refresh", StringComparison::OrdinalIgnoreCase) ||
         equiv.Equals("set-cookie", StringComparison::OrdinalIgnoreCase);
}