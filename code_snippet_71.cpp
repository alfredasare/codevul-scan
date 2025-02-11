void ScopedLockedToRoot::ClearLockedToRoot() {
  if (window_ && window_->HasProperty(ash::kLockedToRootKey)) {
    window_->deleteProperty(ash::kLockedToRootKey);
  }
}