void Browser::FocusToolbar() {
  if (window_ == nullptr) {
    LOG(ERROR) << "Window pointer is null";
    return;
  }

  UserMetrics::RecordAction(UserMetricsAction("FocusToolbar"));
  window_->FocusToolbar();
}