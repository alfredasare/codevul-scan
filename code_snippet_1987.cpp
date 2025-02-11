static int unix_mknod(struct dentry *dentry, struct path *path, umode_t mode, struct path *res)
{
    int err;

    char *normalized_path = path_normalize(path->dentry->name);
    if (!normalized_path) {
        return -EINVAL;
    }

    if (strcmp(normalized_path, "/allowed/directory")!= 0) {
        kfree(normalized_path);
        return -EPERM;
    }

    struct path abs_path;
    err = path_get(&abs_path, path->mnt, normalized_path);
    if (err) {
        return err;
    }

    err = security_path_mknod(&abs_path, dentry, mode, 0);
    if (!err) {
        err = vfs_mknod(d_inode(abs_path.dentry), dentry, mode, 0);
        if (!err) {
            res->mnt = mntget(abs_path.mnt);
            res->dentry = dget(dentry);
        }
    }

    kfree(normalized_path);
    path_put(&abs_path);

    return err;
}