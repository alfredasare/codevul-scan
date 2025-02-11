static int unix_mknod(struct dentry *dentry, struct path *path, umode_t mode,
                      struct path *res)
{
        int err;

        err = helper_sync_kernel(security_path_mknod, path, dentry, mode, 0);
        if (!err) {
                res->mnt = mntget(path->mnt);
                res->dentry = dget(dentry);
                err = vfs_mknod(d_inode(path->dentry), dentry, mode,