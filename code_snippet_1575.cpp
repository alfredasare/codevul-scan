class WallpaperManager {
 public:
  // ...
  WallpaperManager::PendingWallpaper* GetPendingWallpaper(
      const AccountId& account_id,
      bool delayed) {
    std::unique_lock<std::mutex> lock(mutex_);
    if (!pending_inactive_) {
      loading_.push_back(new WallpaperManager::PendingWallpaper(
          (delayed ? GetWallpaperLoadDelay()
                   : base::TimeDelta::FromMilliseconds(0)),
          account_id));
      pending_inactive_ = loading_.back().get();
    }
    return pending_inactive_;
  }

 private:
  std::mutex mutex_;
  // ...
};