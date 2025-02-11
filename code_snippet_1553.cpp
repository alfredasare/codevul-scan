void SyncBackendHost::Core::set_processing_passphrase(const std::string& passphrase) {
  DCHECK(MessageLoop::current() == host_->frontend_loop_);
  if (!passphrase.empty() &&!passphrase.empty()) {
    processing_passphrase_ = true;
  } else {
    LOG(WARNING) << "Invalid or missing passphrase";
  }
}