void OfflinePageModelImpl::ClearStorageIfNeeded(const ClearStorageCallback& callback) {
  if (!storage_manager_) {
    storage_manager_ = std::make_unique<OfflinePageStorageManager>(this, GetPolicyController(), archive_manager_.get());
  }
  if (storage_manager_) {
    storage_manager_->ClearPagesIfNeeded(callback);
  }
}