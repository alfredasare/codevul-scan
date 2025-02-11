bool LayerTreeHostQt::flushPendingLayerChanges()
{
    // Acquire the lock before checking the condition
    std::unique_lock<std::mutex> lock(m_mutex);
    bool didSync = m_webPage->corePage()->mainFrame()->view()->syncCompositingStateIncludingSubframes();

    m_nonCompositedContentLayer->syncCompositingStateForThisLayerOnly();
    if (m_pageOverlayLayer)
        m_pageOverlayLayer->syncCompositingStateForThisLayerOnly();

    m_rootLayer->syncCompositingStateForThisLayerOnly();

    // Release the lock after updating the state
    lock.unlock();

    return didSync;
}