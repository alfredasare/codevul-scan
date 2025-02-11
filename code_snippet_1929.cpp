int cap_inode_need_killpriv(struct dentry *dentry)
{
    struct inode *inode = dentry->d_inode;
    int error;

    if (!dentry ||!dentry->d_inode ||!dentry->d_inode->i_op->getxattr) {
        return 0;
    }

    error = inode->i_op->getxattr(dentry, XATTR_NAME_CAPS, NULL, 0);
    if (error <= 0) {
        return 0;
    }

    return 1;
}