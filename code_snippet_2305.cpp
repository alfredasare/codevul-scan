xfs_inherit_acl(struct inode *inode, struct posix_acl *acl)
{
    umode_t mode = inode->i_mode;
    int error = 0, inherit = 0;
    size_t acl_size = posix_acl_size(acl);

    if (S_ISDIR(inode->i_mode)) {
        error = xfs_set_acl(inode, ACL_TYPE_DEFAULT, acl);
        if (error)
            goto out;
    }

    error = posix_acl_create(&acl, GFP_KERNEL, &mode);
    if (error < 0)
        return error;

    if (error > 0) {
        inherit = 1;
        if (acl_size > sizeof(struct posix_acl)) {
            printk(KERN_ERR "xfs_inherit_acl: Buffer overflow detected\n");
            return -EINVAL;
        }
    }

    error = xfs_set_mode(inode, mode);
    if (error)
        goto out;

    if (inherit)
        error = xfs_set_acl(inode, ACL_TYPE_ACCESS, acl);

out:
    posix_acl_release(acl);
    return error;
}