class StyleResolver {
public:
    // ...
    void resetFontSelector() {
        if (m_fontSelector && shouldCreateNewFontSelector()) {
            m_fontSelector->unregisterForInvalidationCallbacks(this);
            m_fontSelector->clearDocument();
            invalidateMatchedPropertiesCache();

            CSSFontSelector::destroy(m_fontSelector); // Decrease the reference count and potentially destroy the object

            m_fontSelector = CSSFontSelector::create(&m_document);
            m_fontSelector->registerForInvalidationCallbacks(this);
        }
    }

private:
    bool shouldCreateNewFontSelector() const {
        // Implement your resource management logic here, e.g., based on time, number of objects, or available resources
        // Return true if a new object should be created, false otherwise
    }

    CSSFontSelector* m_fontSelector;
};