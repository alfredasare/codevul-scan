bool SharedMemory::Delete(const std::string& name) {
  FilePath path;
  if (!IsValidName(name)) {
    return false;
  }
  name = SanitizeName(name);
  if (!FilePathForMemoryName(name, &path)) {
    return false;
  }
  if (file_util::PathExists(path)) {
    return base::Delete(path, false);
  }
  return true;
}

std::string SanitizeName(const std::string& name) {
  static const std::set<char> valid_chars = {"a-zA-Z0-9-_."};
  std::string sanitized_name;
  for (char c : name) {
    if (valid_chars.find(c)!= valid_chars.end()) {
      sanitized_name += c;
    }
  }
  return sanitized_name;
}