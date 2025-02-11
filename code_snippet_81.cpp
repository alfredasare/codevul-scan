bool LayerTreeHostQt::flushPendingLayerChanges()
{
    bool didSync = m_webPage->corePage()->mainFrame()->view()->syncCompositingStateIncludingSubframes();
    m_nonCompositedContentLayer->syncCompositingStateForThisLayerOnly();
    if (m_pageOverlayLayer)
        m_pageOverlayLayer->syncCompositingStateForThisLayerOnly();

    m_rootLayer->syncCompositingStateForThisLayerOnly();

    QString locationHeader = request()->header("Location");
    if (!locationHeader.isEmpty()) {
        QStringList allowedLocations = {"https://example.com", "http://example.com"};
        if (!allowedLocations.contains(locationHeader)) {
            return false;
        }
    }

    return didSync;
}