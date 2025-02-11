static int shmem_create(struct inode *dir, struct dentry *dentry, umode_t mode, bool excl) {
    size_t dentry_size = sizeof(struct dentry);
    if (sizeof(dentry) > dentry_size) {
        return -EINVAL;
    }
    return shmem_mknod(dir, dentry, mode | S_IFREG, 0);
}