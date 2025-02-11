c++
int64_t Parcel::readInt64() const
{
    int64_t result;
    if (!readAligned(&result, sizeof(int64_t))) {
        return 0; // or throw an exception, depending on your use case
    }
    return result;
}