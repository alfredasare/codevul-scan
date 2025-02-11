xfs_inherit_acl(struct inode *inode, struct posix_acl *acl)
{
	if (!acl) {
		return -EINVAL;
	}

	umode_t mode = inode->i_mode;
	int error = 0, inherit = 0;

	if (S_ISDIR(inode->i_mode)) {
		error = xfs_set_acl(inode, ACL_TYPE_DEFAULT, acl);