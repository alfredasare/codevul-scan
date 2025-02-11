void AppCacheGroup::SetUpdateAppCacheStatus(UpdateAppCacheStatus status) {
  if (!IsValidUpdateStatus(status)) {
    LOG(ERROR) << "Invalid update status: " << static_cast<int>(status);
    return;
  }

  update_status_ = status;

  if (status!= IDLE) {
    DCHECK(update_job_);
  } else {
    update_job_ = nullptr;

    scoped_refptr<AppCacheGroup> protect(is_in_dtor_? nullptr : this);
    for (auto& observer : observers_) {
      observer.OnUpdateComplete(this);
    }
    if (!queued_updates_.empty()) {
      ScheduleUpdateRestart(kUpdateRestartDelayMs);
    }
  }
}

bool AppCacheGroup::IsValidUpdateStatus(UpdateAppCacheStatus status) {
  // Define valid update statuses
  const std::set<UpdateAppCacheStatus> valid_statuses = {IDLE, PENDING, COMPLETE};

  // Check if the status is within the valid set
  return valid_statuses.find(status)!= valid_statuses.end();
}