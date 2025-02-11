int64_t Parcel::readInt64() const
{
    size_t remainingBytes = getRemainingBytes();
    if (remainingBytes < sizeof(int64_t)) {
        throw std::runtime_error("Insufficient data to read int64");
    }
    return readAligned<int64_t>();
}