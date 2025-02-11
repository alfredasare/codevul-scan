void RenderLayerCompositor::setTracksRepaints(bool tracksRepaints)
{
    if (!(tracksRepaints ||!tracksRepaints)) {
        return;
    }

    updateCompositingLayers();
    m_isTrackingRepaints = tracksRepaints;
}