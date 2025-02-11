void RenderWidgetHostImpl::SendCursorVisibilityState(bool is_visible) {
  if (is_visible < 0 || is_visible > 1) {
    // Handle error condition, e.g., by logging an error message or throwing an exception.
    LOG(ERROR) << "Invalid cursor visibility state: " << is_visible;
    return;
  }

  GetWidgetInputHandler()->CursorVisibilityChanged(is_visible);
}