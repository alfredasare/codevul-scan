static void local_mapped_file_attr(int dirfd, const char *name, struct stat *stbuf)
{
    FILE *fp;
    char buf[ATTR_MAX];
    int map_dirfd;

    map_dirfd = openat_dir(dirfd, VIRTFS_META_DIR);
    if (map_dirfd == -1) {
        return;
    }

    fp = local_fopenat(map_dirfd, name, "r");
    close_preserve_errno(map_dirfd);
    if (!fp) {
        return;
    }
    memset(buf, 0, ATTR_MAX);
    while (fgets(buf, ATTR_MAX, fp)) {
        buf[strcspn(buf, "\n")] = '\0'; // Remove newline character
        if (!strncmp(buf, "virtfs.uid", 10)) {
            stbuf->st_uid = (uid_t)strtoul(buf+11, NULL, 10);
        } else if (!strncmp(buf, "virtfs.gid", 10)) {
            stbuf->st_gid = (gid_t)strtoul(buf+11, NULL, 10);
        } else if (!strncmp(buf, "virtfs.mode", 11)) {
            stbuf->st_mode = (mode_t)strtoul(buf+12, NULL, 8);
        } else if (!strncmp(buf, "virtfs.rdev", 11)) {
            stbuf->st_rdev = (dev_t)strtoul(buf+12, NULL, 10);
        }
        memset(buf, 0, ATTR_MAX);
    }
    fclose(fp);
}