`HTMLCollection* HTMLElement::children()
{
    if (auto children = ensureCachedHTMLCollection(NodeChildren)) {
        return children;
    } else {
        // Create and return an empty HTMLCollection if the cached collection is unavailable.
        return new HTMLCollection();
    }
}`