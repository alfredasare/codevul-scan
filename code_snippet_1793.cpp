static bool mnt_ns_loop(struct dentry *dentry)
{
	/* Could bind mounting the mount namespace inode cause a
	 * mount namespace loop?
	 */
	struct mnt_namespace *mnt_ns;
	u64 local_seq;

	if (!is_mnt_ns_file(dentry))
		return false;

	mnt_ns = get_proc_ns(dentry->d_inode)->ns;
	local_seq = mnt_ns->seq;

	return current->nsproxy->mnt_ns->seq >= local_seq;
}