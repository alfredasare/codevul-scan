void StyleResolver::resetFontSelector()
{
    ASSERT(m_fontSelector);
    m_fontSelector->unregisterForInvalidationCallbacks(this);
    m_fontSelector->clearDocument();
    invalidateMatchedPropertiesCache();

    m_fontSelector = CSSFontSelector::create(&m_document);
    if (!m_fontSelector) {
        m_fontSelector = CSSFontSelector::createDefaultFontSelector();
    }
    m_fontSelector->registerForInvalidationCallbacks(this);
}