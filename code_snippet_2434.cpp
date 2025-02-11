int dexOptCreateEmptyHeader(int fd)
{
 DexOptHeader optHdr = {0};
 ssize_t actual;

 assert(lseek(fd, 0, SEEK_CUR) == 0);

 /*
 * The data is only expected to be readable on the current system, so
 * we just write the structure. We do need the file offset to be 64-bit
 * aligned to fulfill a DEX requirement.
 */
 assert((offsetof(DexOptHeader, dexOffset) & 0x07) == 0);
 actual = write(fd, &optHdr, sizeof(optHdr));
 if (actual != sizeof(optHdr)) {
 int err = errno ? errno : -1;
 ALOGE("opt header write failed: %s", strerror(errno));
 return errno;
 }

 return 0;
}