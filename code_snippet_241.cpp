LayoutRect RenderBox::overflowRectForPaintRejection() const
{
    LayoutRect overflowRect = visualOverflowRect();
    if (!m_overflow ||!usesCompositedScrolling())
        return overflowRect;

    overflowRect.unite(layoutOverflowRect());
    int xOffset = std::max(0, -static_cast<int>(scrolledContentOffset().x));
    int yOffset = std::max(0, -static_cast<int>(scrolledContentOffset().y));
    overflowRect.move(xOffset, yOffset);
    return overflowRect;
}