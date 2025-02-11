static int ovl_unlink(struct inode *dir, struct dentry *dentry)
{
    if (dentry->d_name.len > OVL_MAX_DENTRY_NAME_LENGTH) {
        return -EINVAL;
    }

    return ovl_do_remove(dentry, false);
}