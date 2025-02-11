void DataPipeConsumerDispatcher::OnPortStatusChanged() {
  auto* current_context = RequestContext::current();
  if (!current_context) {
    return;
  }

  base::AutoLock lock(lock_);

  if (transferred_)
    return;

  DVLOG(1) << "Control port status changed for data pipe producer " << pipe_id_;

  UpdateSignalsStateNoLock();
}