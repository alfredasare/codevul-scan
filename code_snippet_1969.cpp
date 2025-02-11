static int proc_sys_delete(const struct dentry *dentry)
{
	struct super_block *sb = d_sb(dentry);
	int ret;
	mutex_lock(&sb->s_umount);
	ret = !!PROC_I(d_inode(dentry))->sysctl->unregistering;
	mutex_unlock(&sb->s_umount);
	return ret;
}