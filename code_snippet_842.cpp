// Fixed code:
#define MAX_BLKSIZE 1048576

iperf_get_test_blksize(struct iperf_test *ipt)
{
    // Add a check for maximum allowable blksize
    if (ipt->settings->blksize > MAX_BLKSIZE) {
        return MAX_BLKSIZE;
    }

    return ipt->settings->blksize;
}