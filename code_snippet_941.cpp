void WebMediaPlayerImpl::OnDisplayTypeChanged(WebMediaPlayer::DisplayType display_type) {
  if (!watch_time_reporter_) return;

  // Define a whitelist of allowed display types
  static const std::set<WebMediaPlayer::DisplayType> allowed_display_types = {
    WebMediaPlayer::DisplayType::kInline,
    WebMediaPlayer::DisplayType::kFullscreen,
    WebMediaPlayer::DisplayType::kPictureInPicture
  };

  // Validate the display type
  if (allowed_display_types.find(display_type) == allowed_display_types.end()) {
    LOG(WARNING) << "Invalid display type: " << display_type;
    return;
  }

  // Use a switch statement to call the correct function
  switch (display_type) {
    case WebMediaPlayer::DisplayType::kInline:
      watch_time_reporter_->OnDisplayTypeInline();
      break;
    case WebMediaPlayer::DisplayType::kFullscreen:
      watch_time_reporter_->OnDisplayTypeFullscreen();
      break;
    case WebMediaPlayer::DisplayType::kPictureInPicture:
      watch_time_reporter_->OnDisplayTypePictureInPicture();
      break;
  }
}