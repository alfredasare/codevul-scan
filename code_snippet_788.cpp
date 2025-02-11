bool WebLocalFrameImpl::IsProvisional() const {
  ASSERT(frame_);
  return frame_ && frame_->IsProvisional();
}