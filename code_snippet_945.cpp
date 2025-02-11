string16 ToUpper(const string16& string) {
  if (!IsValidInputString(string)) {
    throw std::invalid_argument("Invalid input string");
  }

  icu::UnicodeString unicode_string(string.c_str(), string.size());
  unicode_string.toUpper();
  return string16(unicode_string.getBuffer(), unicode_string.length());
}

bool IsValidInputString(const string16& string) {
  for (char16 c : string) {
    if (!isalnum(c) && c!= '_') { // Only allow alphanumeric characters and underscores
      return false;
    }
  }
  return true;
}