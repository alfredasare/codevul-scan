static int CallStat(const char *path, stat_wrapper_t *sb) {
    int ret = 0;
    base::ThreadRestrictions::AssertIOAllowed();
    ret = stat(path, sb);
    if (ret == -1) {
        perror("stat");
        return -1;
    }
    return ret;
}