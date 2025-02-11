bool WebLocalFrameImpl::IsViewSourceModeEnabled() const {
  if (!GetFrame()) {
    return false;
  }
  auto framePermission = GetFrame()->GetPermission();
  if (!framePermission->IsAllowed()) {
    return false;
  }
  return framePermission->InViewSourceMode();
}