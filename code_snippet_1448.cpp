int generic_permission(struct inode *inode, int mask)
{
    int ret;

    ret = acl_permission_check(inode, mask);
    if (ret < 0) {
        return ret;
    }

    // Rest of the code remains the same
}