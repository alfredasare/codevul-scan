void SyncBackendHost::Core::DoUpdateEnabledTypes() {
  DCHECK(host_->core_thread_.message_loop() == MessageLoop::current());
  syncapi_->UpdateEnabledTypes();
}