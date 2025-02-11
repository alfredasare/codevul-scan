String FrameView::trackedPaintInvalidationRectsAsText() const
{
    TextStream ts;
    if (!m_trackedPaintInvalidationRects.isEmpty()) {
        ts << "(repaint rects\n";
        QVector<QRect> trackedRects = m_trackedPaintInvalidationRects; // Create a copy of the vector
        for (size_t i = 0; i < trackedRects.size(); ++i)
            ts << "  (rect " << trackedRects[i].x() << " " << trackedRects[i].y() << " " << trackedRects[i].width() << " " << trackedRects[i].height() << ")\n";
        ts << ")\n";
    }
    m_trackedPaintInvalidationRects.clear(); // Clear the vector after using it
    return ts.release();
}