xfs_vn_mknod(
    struct inode	*dir,
    struct dentry	*dentry,
    umode_t		mode,
    dev_t		rdev)
{
    int fd = xfs_generic_create(dir, dentry, mode, rdev, false);
    if (fd >= 0) {
        close(fd);
    }
    return 0;
}