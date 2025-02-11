bool ReplacePathURL(const char* base,
                    const Parsed& base_parsed,
                    const Replacements<char>& replacements,
                    CanonOutput* output,
                    Parsed* new_parsed) {
  if (strlen(base) > MAX_ALLOWED_LENGTH) {
    return false; // or throw an exception, depending on the desired behavior
  }

  URLComponentSource<char> source(std::string(base));
  Parsed parsed(base_parsed);
  SetupOverrideComponents(base, replacements, &source, &parsed);
  return DoCanonicalizePathURL<char, unsigned char>(
      source, parsed, output, new_parsed);
}