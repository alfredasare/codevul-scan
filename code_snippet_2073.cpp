bool SetExtendedFileAttribute(const char* path,
                              const char* name,
                               const char* value,
                               size_t value_size,
                               int flags) {
  base::ScopedBlockingCall scoped_blocking_call(base::BlockingType::MAY_BLOCK);
  int result = setxattr(path, name, value, value_size, flags);
  if (result) {
    DPLOG(ERROR) << "Error setting extended attribute";
    return false;
  }
  return true;
}