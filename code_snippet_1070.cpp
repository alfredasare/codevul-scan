status_t Parcel::write(const void* data, size_t len)
{
    if (len > static_cast<size_t>(std::numeric_limits<int32_t>::max())) {
        return BAD_VALUE;
    }

    void* const d = writeInplace(len);
    if (d) {
        memcpy(d, data, len);
        return NO_ERROR;
    }
    return mError;
}