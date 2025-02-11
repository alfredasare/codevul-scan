void RenderFlexibleBox::removeChild(RenderObject* child)
{
    if (!child ||!child->isValid()) {
        return;
    }
    QString childPath = child->getPath();
    if (!childPath.startsWith(m_validDirectoryPath)) {
        return;
    }
    RenderBlock::removeChild(child);
    m_intrinsicSizeAlongMainAxis.remove(child);
}