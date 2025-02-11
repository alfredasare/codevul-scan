#include "base/lock.h"

class VideoCaptureManager {
 public:
  explicit VideoCaptureManager(base::Lock* capture_observers_lock);

  void RemoveAllVideoCaptureObservers();

 private:
  base::Lock* const capture_observers_lock_;
  std::set<VideoCaptureObserver*> capture_observers_;
};

VideoCaptureManager::VideoCaptureManager(base::Lock* capture_observers_lock)
    : capture_observers_lock_(capture_observers_lock) {}

void VideoCaptureManager::RemoveAllVideoCaptureObservers() {
  DCHECK_CURRENTLY_ON(BrowserThread::IO);

  base::Lock lock(*capture_observers_lock_);
  capture_observers_.clear();
}