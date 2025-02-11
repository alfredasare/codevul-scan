static int ovl_unlink(struct inode *dir, struct dentry *dentry)
{
    struct path target_path, parent_path;
    struct dentry *parent_dentry = dentry->d_parent;
    int ret;

    if (!parent_dentry) {
        return -EINVAL;
    }

    ret = vfs_get_destruction_parents(dentry, &parent_path, &target_path);
    if (ret) {
        return ret;
    }

    if (!parent_path.mnt || !target_path.mnt ||
        parent_path.mnt != target_path.mnt) {
        path_put(&parent_path);
        path_put(&target_path);
        return -EINVAL;
    }

    if (path_compare(&parent_path, &parent_dentry->d_path)) {
        path_put(&parent_path);
        path_put(&target_path);
        return -EINVAL;
    }

    ret = vfs_readlink(&target_path, NULL, 0);
    path_put(&target_path);
    if (ret < 0) {
        return ret;
    }

    ret = ovl_do_remove(dentry, true);
    if (ret == -EMLINK) {
        ret = -ENOSR;
    }

    return ret;
}