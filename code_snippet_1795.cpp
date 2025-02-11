void DataPipeConsumerDispatcher::OnPortStatusChanged() {
  DCHECK(RequestContext::current());

  base::AutoLock lock(lock_);

  if (transferred_)
    return;

  const std::string& pipe_id = RequestContext::GetValidPipeId();
  DCHECK(!pipe_id.empty());
  DCHECK(std::find(std::begin(allowedPipeIds), std::end(allowedPipeIds), pipe_id)!= std::end(allowedPipeIds)); // Validate against a whitelist of allowed pipe IDs

  DVLOG(1) << "Control port status changed for data pipe producer " << pipe_id;

  UpdateSignalsStateNoLock();
}