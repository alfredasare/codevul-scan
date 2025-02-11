static int get_fsuid(void)
{
    int uid = get_proc_fs_id(/*UID*/'U');
    if (uid == -1) {
        syslog(LOG_ERR, "Failed to retrieve file system ID");
    } else {
        return uid;
    }
}