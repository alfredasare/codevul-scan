~ScopedLockedToRoot() {
  if (!window_) {
    throw std::runtime_error("window_ is a null pointer");
    // or return; depending on your use case
  }
  window_->ClearProperty(ash::kLockedToRootKey);
}