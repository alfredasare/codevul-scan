if (_fsm_debug && rc && errno!= ENOENT) {
    char buffer[256];
    snprintf(buffer, sizeof(buffer), " %8s (%s, ost) %s\n",
             __func__, path, (rc < 0? strerror(errno) : ""));
    rpmlog(RPMLOG_DEBUG, buffer);
}