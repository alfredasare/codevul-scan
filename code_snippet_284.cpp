void ProfileSyncService::RemoveObserver(Observer* observer) {
  std::lock_guard<std::mutex> lock(mutex_);
  observers_.erase(observer);
}