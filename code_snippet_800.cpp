gfx::Size DelegatedFrameHost::GetRequestedRendererSize() const {
if (resize_lock_ && resize_lock_->expected_size().IsEmpty())
return client_->DelegatedFrameHostDesiredSizeInDIP();
else if (resize_lock_)
return resize_lock_->expected_size();
return gfx::Size();
}