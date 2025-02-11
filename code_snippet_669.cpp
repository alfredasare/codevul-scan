void DesktopWindowTreeHostX11::BeforeActivationStateChanged() {
> #if (defined(OS_LINUX) && defined(USE_X11))
  was_active_ = IsActive();
  had_pointer_ = has_pointer_ && IsActive();
  had_pointer_grab_ = has_pointer_grab_ && IsActive();
  had_window_focus_ = has_window_focus_ && IsActive();
> #else
  was_active_ = IsActive();
  had_pointer_ = has_pointer_;
  had_pointer_grab_ = has_pointer_grab_;
  had_window_focus_ = has_window_focus_;
> #endif
}