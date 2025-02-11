#include <boost/algorithm/string/predicate.hpp>

static std::string FixupPath(const std::string& text) {
  DCHECK(!text.empty());

  FilePath::StringType filename;
  std::string sanitized_text;

  // Sanitize the input string to only allow allowed characters
  for (char c : text) {
    if (boost::algorithm::isalnum(c) || c == '.' || c == '_' || c == '-') {
      sanitized_text += c;
    }
  }

  FilePath input_path(UTF8ToWide(sanitized_text));
  PrepareStringForFileOps(input_path, &filename);

  if (filename.length() > 1 && filename[1] == '|')
    filename[1] = ':';
#elif defined(OS_POSIX)
  FilePath input_path(sanitized_text);
  PrepareStringForFileOps(input_path, &filename);
  if (filename.length() > 0 && filename[0] == '~')
    filename = FixupHomedir(filename);
#endif

  GURL file_url = net::FilePathToFileURL(FilePath(filename));
  if (file_url.is_valid()) {
    return UTF16ToUTF8(net::FormatUrl(file_url, std::string(),
        net::kFormatUrlOmitUsernamePassword, UnescapeRule::NORMAL, NULL,
        NULL, NULL));
  }

  return text;
}