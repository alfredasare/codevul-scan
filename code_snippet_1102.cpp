rdpsnd_queue_empty(void)
{
    size_t queue_size = queue_hi - queue_lo;
    if (queue_size < 0) {
        queue_size = (size_t)-1; // queue is empty
    }
    return (queue_size == 0);
}