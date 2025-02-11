int vfs_rmdir(struct inode *dir, struct dentry *dentry)
{
    int error = may_delete(dir, dentry, 1);

    if (error)
        return error;

    if (!dir->i_op->rmdir)
        return -EPERM;

    vfs_dq_init(dir);

    mutex_lock(&dentry->d_inode->i_mutex);
    dentry_unhash(dentry);

    if (!dentry->d_parent ||!is_path_below_root(dentry->d_parent)) {
        error = -EINVAL;
        goto out;
    }

    if (d_mountpoint(dentry))
        error = -EBUSY;
    else {
        error = security_inode_rmdir(dir, dentry);
        if (!error) {
            error = dir->i_op->rmdir(dir, dentry);
            if (!error)
                dentry->d_inode->i_flags |= S_DEAD;
        }
    }
    mutex_unlock(&dentry->d_inode->i_mutex);
    if (!error) {
        d_delete(dentry);
    }
    dput(dentry);

    return error;
}

bool is_path_below_root(struct dentry *dentry)
{
    struct dentry *parent = dentry;
    while (parent && parent!= root_dentry) {
        parent = parent->d_parent;
    }
    return parent == root_dentry;
}