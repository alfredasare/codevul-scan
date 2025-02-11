void Element::setMinimumSizeForResizing(const LayoutSize& size)
{
    if (!hasRareData() || (size != defaultMinimumSizeForResizing() && !(size > maxAllowedSize)))
        return;
    ensureElementRareData()->setMinimumSizeForResizing(size);
}