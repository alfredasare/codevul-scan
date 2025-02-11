gfx::Size DelegatedFrameHost::GetRequestedRendererSize() const {
  gfx::Size size;
  if (resize_lock_) {
    size = resize_lock_->expected_size();
  } else {
    size = client_->DelegatedFrameHostDesiredSizeInDIP();
  }
  return size;
}