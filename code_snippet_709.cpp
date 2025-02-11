size_t iperf_get_test_blksize(struct iperf_test *ipt)
{
    size_t blksize = (size_t)(ipt->settings->blksize);
    if (blksize < IPERF_MIN_BLKSIZE || blksize > IPERF_MAX_BLKSIZE) {
        // Handle invalid value, e.g., return an error or default value
    }
    return blksize;
}