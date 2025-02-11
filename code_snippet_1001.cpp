class AppCacheGroup {
 public:
  // ...

 private:
  // ...
  std::mutex update_job_mutex_;
  // ...
};

void AppCacheGroup::SetUpdateAppCacheStatus(UpdateAppCacheStatus status) {
  std::unique_lock<std::mutex> lock(update_job_mutex_);

  if (status == update_status_)
    return;

  update_status_ = status;

  if (status != IDLE) {
    DCHECK(update_job_);
  } else {
    update_job_ = nullptr;

    scoped_refptr<AppCacheGroup> protect(is_in_dtor_ ? nullptr : this);
    for (auto& observer : observers_)
      observer.OnUpdateComplete(this);
    if (!queued_updates_.empty())
      ScheduleUpdateRestart(kUpdateRestartDelayMs);
  }
}