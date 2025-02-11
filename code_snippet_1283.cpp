bool rdpsnd_queue_empty(const size_t queue_size, const uint32_t queue_lo, const uint32_t queue_hi)
{
    if (queue_lo >= queue_size || queue_hi >= queue_size) {
        return true;
    }

    return (queue_lo == queue_hi);
}