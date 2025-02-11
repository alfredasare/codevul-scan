#include <limits>

status_t Parcel::write(const void* data, size_t len)
{
    if (len > std::numeric_limits<int>::max()) {
        return BAD_VALUE;
    }

    void* const d = writeInplace(len);
    if (d) {
        memcpy(d, data, len);
        return NO_ERROR;
    }
    return mError;
}