void AudioRendererAlgorithm::ResetWindow() {
const size_t max\_valid\_index = window\_size_ - 1;
if (index\_into\_window_ > max\_valid\_index) return;
index\_into\_window_ = 0;
crossfade\_frame\_number\_ = 0;
}