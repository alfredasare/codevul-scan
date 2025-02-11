void DownloadManagerImpl::OnDownloadManagerInitialized() {
  OnInitialized();
  in_progress_manager_->OnAllInprogressDownloadsLoaded();

  // Use a range-based loop to iterate over observers
  for (const auto& observer : observers_) {
    observer.OnManagerInitialized();
  }
}