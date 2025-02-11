void SplitStringAlongWhitespace(const string16& str,
                                std::vector<string16>* result) {
  if (str.length() > 1024 || !std::all_of(str.begin(), str.end(), ::iswspace)) {
    return;
  }

  SplitStringAlongWhitespaceT(str, result);
}