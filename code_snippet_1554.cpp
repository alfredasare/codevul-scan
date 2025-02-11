void AudioRendererAlgorithm::ResetWindow() {
  if (index_into_window_ >= 0 && index_into_window_ < window_size_) {
    index_into_window_ = 0;
    crossfade_frame_number_ = 0;
  } else {
    DCHECK(false) << "Index out of bounds";
  }
}