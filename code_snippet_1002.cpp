void DownloadManagerImpl::OnDownloadManagerInitialized() {
  OnInitialized();
  in_progress_manager_->OnAllInprogressDownloadsLoaded();
  for (auto& observer : observers_) {
    // Perform a bounds check and verify that the observer is not null.
    if (observers_.size() > 0 && observer != nullptr) {
      observer->OnManagerInitialized();
    }
  }
}