bool ReplacePathURL(const char* base,
                     const Parsed& base_parsed,
                     const Replacements<base::char16>& replacements,
                     CanonOutput* output,
                     Parsed* new_parsed) {
  if (!IsValidBasePath(base)) {
    return false; // or throw an exception, depending on your error handling strategy
  }
  RawCanonOutput<1024> utf8;
  URLComponentSource<char> source(base);
  Parsed parsed(base_parsed);
  SetupUTF16OverrideComponents(base, replacements, &utf8, &source, &parsed);
  return DoCanonicalizePathURL<char, unsigned char>(source, parsed, output, new_parsed);
}

#include <boost/filesystem.hpp>

bool IsValidBasePath(const char* base) {
  namespace fs = boost::filesystem;
  fs::path path(base);
  return fs::is_directory(path) || fs::is_regular_file(path);
}