bool isWithinBounds(const LayoutRect& rect, int maxWidth, int maxHeight) const {
    return (rect.width() <= maxWidth && rect.height() <= maxHeight);
}

void limitUniteOperations(int maxUniteOperations) const {
    static int uniteOperations = 0;
    if (++uniteOperations > maxUniteOperations) {
        throw std::runtime_error("Unite operations limit reached");
    }
}

LayoutRect RenderBox::overflowRectForPaintRejection() const
{
    constexpr int maxWidth = 1000;
    constexpr int maxHeight = 1000;
    constexpr int maxUniteOperationsLimit = 10;

    LayoutRect overflowRect = visualOverflowRect();
    if (!m_overflow || !usesCompositedScrolling())
        return overflowRect;

    if (isWithinBounds(overflowRect, maxWidth, maxHeight) && maxUniteOperationsLimit > 0) {
        limitUniteOperations(maxUniteOperationsLimit);
        overflowRect.unite(layoutOverflowRect());
    }

    if (isWithinBounds(overflowRect, maxWidth, maxHeight)) {
        overflowRect.move(-scrolledContentOffset());
    }

    return overflowRect;
}