bool ThreadSafeMatch(const Vector<UChar, inlineCapacity>& vector, const QualifiedName& qname) {
  std::string_view localName = qname.LocalName().Impl();
  localName = SanitizeLocalName(localName);
  return EqualIgnoringNullity(vector, localName);
}

std::string SanitizeLocalName(const std::string_view& name) {
  static const std::set<char> allowedChars = {'a', 'b',...}; // Define allowed characters
  std::string sanitizedName;
  for (char c : name) {
    if (allowedChars.count(c) > 0) {
      sanitizedName += c;
    }
  }
  return sanitizedName;
}