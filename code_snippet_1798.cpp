void SyncManager::SyncInternal::OnIPAddressChangedImpl() {
  DCHECK(thread\_checker\_.CalledOnValidThread());
  auto schedulerObj = scheduler();
  if (schedulerObj)
    schedulerObj->OnConnectionStatusChange();
}