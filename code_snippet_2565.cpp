String Location::toString() const {
  USVStringOrTrustedURL result;
  std::u16string allowed_chars = u"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;=";

  if (href(result) && isInputValid(result.GetAsUSVString(), allowed_chars)) {
    DCHECK(result.IsUSVString());
    return result.GetAsUSVString();
  }

  return "";
}

bool Location::isInputValid(const USVString& input, const std::u16string& allowed_chars) {
  return input.length() <= MAX_INPUT_LENGTH && containsOnly(input, allowed_chars);
}

bool Location::containsOnly(const USVString& input, const std::u16string& allowed_chars) {
  for (uint32_t i = 0; i < input.length(); ++i) {
    if (!allowed_chars.find(input[i])) {
      return false;
    }
  }
  return true;
}