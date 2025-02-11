c++
string16 ToUpper(const string16& string) {
  icu::UnicodeString unicode_string(string.c_str(), string.size());
  unicode_string.toUpper();

  // Reserve space for the null terminator
  const uint32_t required_size = unicode_string.length() + 1;
  if (required_size > string16::kMaxSize) {
    // Handle error case, e.g. by allocating a larger buffer or returning an error code
    // ...
    return {};
  }

  // Resize the destination string to fit the converted string
  string16 dest_string;
  dest_string.reserve(required_size);
  dest_string.assign(unicode_string.getBuffer(), unicode_string.length());

  return dest_string;
}