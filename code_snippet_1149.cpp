void RenderBox::absoluteRects(Vector<LayoutRect>& rects, const LayoutPoint& accumulatedOffset)
{
if (accumulatedOffset.isNull())
return;
rects.append(LayoutRect(accumulatedOffset, size()));
}