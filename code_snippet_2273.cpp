allocbuf(BUF *bp, int fd, int blksize)
{
    size_t size;
#ifdef HAVE_STRUCT_STAT_ST_BLKSIZE
    struct stat stb;

    if (fstat(fd, &stb) < 0) {
        run_err("fstat: %s", strerror(errno));
        return (0);
    }

    if (!S_ISREG(stb.st_mode) || !S_IRUSR & stb.st_mode) {
        run_err("File is not readable");
        return (0);
    }

    size = ROUNDUP(stb.st_blksize, blksize);
    if (size == 0)
        size = blksize;
#else /* HAVE_STRUCT_STAT_ST_BLKSIZE */
    size = blksize;
#endif /* HAVE_STRUCT_STAT_ST_BLKSIZE */

    //... rest of the function...
}