int dexOptCreateEmptyHeader(int fd)
{
    DexOptHeader optHdr;
    ssize_t actual;

    assert(lseek(fd, sizeof(optHdr) - 1, SEEK_SET) == sizeof(optHdr) - 1);

    memset(&optHdr, 0, sizeof(optHdr));
    optHdr.dexOffset = sizeof(optHdr);
    actual = write(fd, &optHdr, sizeof(optHdr));
    if (actual != sizeof(optHdr)) {
        int err = errno ? errno : -1;
        ALOGE("opt header write failed: %s", strerror(errno));
        return errno;
    }

    return 0;
}