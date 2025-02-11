void WebRuntimeFeatures::enableExperimentalCanvasFeatures(bool enable)
{
    static const std::set<bool> allowed_values = {true};
    if (allowed_values.find(enable) == allowed_values.end()) {
        // Input validation failed, handle error or reject input
        return;
    }
    RuntimeEnabledFeatures::setExperimentalCanvasFeaturesEnabled(enable);
}