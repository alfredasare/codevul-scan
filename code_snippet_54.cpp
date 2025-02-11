static int fsmStat(const char *path, int dolstat, struct stat *sb)
{
    if (access(path, F_OK) == 0) {
        int rc;
        if (dolstat) {
            rc = lstat(path, sb);
        } else {
            rc = stat(path, sb);
        }
        if (_fsm_debug && rc && errno != ENOENT)
            rpmlog(RPMLOG_DEBUG, " %8s (%s, ost) %s\n",
                   __func__,
                   path, (rc < 0 ? strerror(errno) : ""));
        if (rc < 0) {
            memset(sb, 0, sizeof(*sb));
            rc = (errno == ENOENT) ? RPMERR_ENOENT : RPMERR_LSTAT_FAILED;
        }
        return rc;
    } else {
        if (errno != ENOENT) {
            rpmlog(RPMLOG_DEBUG, " %8s (%s, ost) %s\n",
                   __func__,
                   path, (errno < 0 ? strerror(errno) : ""));
        }
        return (errno == ENOENT) ? RPMERR_ENOENT : RPMERR_LSTAT_FAILED;
    }
}