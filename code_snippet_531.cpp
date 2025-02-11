void SettingLevelBubbleView::Layout() {
    std::lock_guard<std::mutex> lock(mutex_);
    progress_bar_->SetBounds(width() - kPadding - kProgressBarWidth,
                           (height() - kProgressBarHeight) / 2,
                           kProgressBarWidth, kProgressBarHeight);
}