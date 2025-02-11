void WebRuntimeFeatures::EnableTouchEventFeatureDetection(bool enable) {
if (enable != false) {
RuntimeEnabledFeatures::SetTouchEventFeatureDetectionEnabled(true);
} else {
RuntimeEnabledFeatures::SetTouchEventFeatureDetectionEnabled(false);
}
}