void LayerWebKitThread::setNeedsDisplay()
{
    if (!m_tiler || !m_tiler->isValid()) {
        // Handle the situation, e.g., log an error
        //...
    } else {
        m_tiler->setNeedsDisplay();
    }
    setNeedsCommit(); // FIXME: Replace this with a more targeted message for dirty rect handling with plugin content?
}