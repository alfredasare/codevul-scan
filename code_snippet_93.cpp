void RenderLayerCompositor::setTracksRepaints(bool tracksRepaints)
{
    // Add input validation
    if (tracksRepaints == true || tracksRepaints == false) {
        updateCompositingLayers();
        m_isTrackingRepaints = tracksRepaints;
    } else {
        // Handle invalid input case appropriately (e.g., throw an exception, log an error, etc.)
        throw std::invalid_argument("The tracksRepaints parameter must be a boolean value.");
    }
}