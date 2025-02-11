void SyncManager::SyncInternal::OnIPAddressChangedImpl() {
  DCHECK(thread_checker_.CalledOnValidThread());
  try {
    if (scheduler())
      scheduler()->OnConnectionStatusChange();
  } catch (const std::exception& e) {
    LOG(ERROR) << "Exception caught: " << e.what();
    throw; // Re-throw the exception
  }
}