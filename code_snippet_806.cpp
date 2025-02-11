void Browser::FocusToolbar() {
    UserMetrics::RecordAction(UserMetricsAction("FocusToolbar"));
    if (window_->GetFocusToolbarSize() > 0) {
        char buffer[window_->GetFocusToolbarSize()];
        window_->GetFocusToolbar(buffer, window_->GetFocusToolbarSize());
    } else {
        // Handle the case when the buffer size is invalid
        // For example, you can log an error message or throw an exception
        std::cerr << "Error: Invalid buffer size" << std::endl;
        //...
    }
}