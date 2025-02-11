c++
void SyncBackendHost::Core::DoUpdateEnabledTypes() {
  std::unique_lock<std::mutex> lock(host_->core_thread_mutex_);
  if (host_->IsCoreThread()) {
    syncapi_->UpdateEnabledTypes();
  }
}