void WebMediaPlayerImpl::OnDisplayTypeChanged(WebMediaPlayer::DisplayType display_type) {
  if (watch_time_reporter_) {
    auto reporter = watch_time_reporter_;
    switch (display_type) {
      case WebMediaPlayer::DisplayType::kInline:
        reporter->OnDisplayTypeInline();
        break;
      case WebMediaPlayer::DisplayType::kFullscreen:
        reporter->OnDisplayTypeFullscreen();
        break;
      case WebMediaPlayer::DisplayType::kPictureInPicture:
        reporter->OnDisplayTypePictureInPicture();
        break;
    }
  }
}