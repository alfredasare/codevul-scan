bool SetExtendedFileAttribute(const char* path,
                               const char* name,
                               const char* value,
                               size_t value_size,
                               int flags) {
  // Validate the path input to prevent directory traversal attacks
  constexpr char valid_path_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-.";
  for (const char* c = path; *c != '\0'; ++c) {
    bool is_valid_char = false;
    for (const char* vc = valid_path_chars; *vc != '\0'; ++vc) {
      if (*c == *vc) {
        is_valid_char = true;
        break;
      }
    }
    if (!is_valid_char) {
      DPLOG(ERROR) << "Invalid path: " << path;
      return false;
    }
  }

  base::ScopedBlockingCall scoped_blocking_call(base::BlockingType::MAY_BLOCK);
  int result = setxattr(path, name, value, value_size, flags);
  if (result) {
    DPLOG(ERROR) << "Could not set extended attribute " << name << " on file "
                 << path;
    return false;
  }
  return true;
}