void WebRuntimeFeatures::EnableTouchEventFeatureDetection(bool enable) {
  if (!std::isfinite(enable) || enable < 0 || enable > 1) {
    throw std::invalid_argument("Invalid touch event feature detection enable value");
  }
  RuntimeEnabledFeatures::SetTouchEventFeatureDetectionEnabled(enable);
}