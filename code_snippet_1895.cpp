status_t GraphicBuffer::lockAsyncYCbCr(uint32_t usage, const Rect& rect, android_ycbcr *ycbcr, int fenceFd)
{
    if (rect.left < 0 || rect.right > this->width || rect.top < 0 || rect.bottom > this->height) {
        ALOGE("locking pixels (%d,%d,%d,%d) outside of buffer (w=%d, h=%d)",
                rect.left, rect.top, rect.right, rect.bottom,
                this->width, this->height);
        return BAD_VALUE;
    }

    int leftDiff = std::max(0, std::min(rect.left, this->width) - 0); // safe arithmetic
    int rightDiff = std::max(0, std::min(this->width, rect.right) - rect.left);
    int topDiff = std::max(0, std::min(rect.top, this->height) - 0); // safe arithmetic
    int bottomDiff = std::max(0, std::min(this->height, rect.bottom) - rect.top);

    status_t res = getBufferMapper().lockAsyncYCbCr(handle, usage, Rect(leftDiff, topDiff, rightDiff, bottomDiff), ycbcr, fenceFd);
    return res;
}