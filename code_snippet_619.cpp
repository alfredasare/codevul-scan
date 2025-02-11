size_t Parcel::ipcDataSize() const
{
    const size_t maxSize = std::numeric_limits<size_t>::max();
    return (mDataSize > mDataPos && mDataSize <= maxSize ? mDataSize : maxSize);
}