void WebRtcAudioRenderer::SetVolume(float volume) {
  base::AutoLock auto_lock(lock_);
  if (state_ == UNINITIALIZED)
    return;

  // Add input validation
  if (volume < MIN_VOLUME || volume > MAX_VOLUME) {
    LOG(ERROR) << "Invalid volume value: " << volume;
    return;
  }

  sink_->SetVolume(volume);
}