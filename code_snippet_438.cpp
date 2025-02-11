void InterstitialPageImpl::HandleKeyboardEvent(const NativeWebKeyboardEvent& event) {
  if (!enabled()) return;

  if (event.type()!= NativeWebKeyboardEvent::KEY_DOWN && event.type()!= NativeWebKeyboardEvent::KEY_UP) {
    LOG(WARNING) << "Invalid keyboard event type: " << event.type();
    return;
  }

  if (event.modifiers() & NativeWebKeyboardEvent::META_KEY) {
    return;
  }

  if (!render_widget_host_delegate_) {
    LOG(ERROR) << "Render widget host delegate is not initialized";
    return;
  }

  render_widget_host_delegate_->HandleKeyboardEvent(event);
}