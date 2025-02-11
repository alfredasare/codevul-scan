static void local_mapped_file_attr(int dirfd, const char *name,
                                   struct stat *stbuf)
{
    FILE *fp;
    char buf[ATTR_MAX];
    int map_dirfd;
    size_t name_len;

    map_dirfd = openat_dir(dirfd, VIRTFS_META_DIR);
    if (map_dirfd == -1) {
        return;
    }

    // Validate the 'name' parameter
    name_len = strlen(name);
    if (name_len > MAX_ATTRIBUTE_NAME_LENGTH) {
        return; // or handle the error as needed
    }

    fp = local_fopenat(map_dirfd, name, "r");
    close_preserve_errno(map_dirfd);
    if (!fp) {
        return;
    }
    memset(buf, 0, ATTR_MAX);
    while (fgets(buf, ATTR_MAX, fp)) {
        if (!strncmp(buf, "virtfs.uid", 10)) {
            stbuf->st_uid = atoi(buf+11);
        } else if (!strncmp(buf, "virtfs.gid", 10)) {
            stbuf->st_gid = atoi(buf+11);
        } else if (!strncmp(buf, "virtfs.mode", 11)) {
            stbuf->st_mode = atoi(buf+12);
        } else if (!strncmp(buf, "virtfs.rdev", 11)) {
            stbuf->st_rdev = atoi(buf+12);
        }
        memset(buf, 0, ATTR_MAX);
    }
    fclose(fp);
}