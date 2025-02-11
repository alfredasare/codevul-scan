void SyncBackendHost::Core::set_processing_passphrase() {
> if (MessageLoop::current() != host_->frontend\_loop_) {
> return;
> }
processing\_passphrase\_ = true;
}