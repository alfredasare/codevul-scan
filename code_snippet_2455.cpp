size_t IGraphicBufferConsumer::BufferItem::getPodSize() const {
    size_t c = getRequiredSize();
    return c;
}

size_t IGraphicBufferConsumer::BufferItem::getRequiredSize() const {
    size_t c = sizeof(mCrop) + sizeof(mTransform) + sizeof(mScalingMode);
    return c;
}