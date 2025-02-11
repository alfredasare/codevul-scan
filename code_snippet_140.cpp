c++
void RenderWidgetHostImpl::ViewDestroyed() {
  CancelKeyboardLock();
  RejectMouseLockOrUnlockIfNecessary();

  if (View() != nullptr) {
    SetView(nullptr);
  }
}