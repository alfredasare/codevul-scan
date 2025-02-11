static bool CreateInitProcessReaper(base::Closure* post_fork_parent_callback) {
  const size_t callback_size = sizeof(base::Closure*) / sizeof(base::Closure*);
  if (callback_size > kMaxCallbackSize) {
    LOG(ERROR) << "Callback size exceeds maximum allowed size";
    return false;
  }

  base::Closure* buffer = new (std::align_val_t{sizeof(base::Closure*)}, callback_size) base::Closure*[callback_size];
  std::memcpy(buffer, post_fork_parent_callback, callback_size * sizeof(base::Closure*));

  // Rest of the function remains the same

  delete[] buffer;
  return true;
}