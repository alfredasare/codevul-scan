void RenderWidgetHostImpl::ViewDestroyed() {
  CancelKeyboardLock();
  RejectMouseLockOrUnlockIfNecessary();

  if (view_!= nullptr) {
    SetView(nullptr);
  }
}