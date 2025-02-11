static int ptype_seq_open(struct inode *inode, struct file *file)
{
	struct seq_net_private *snp;
	struct dentry * dent = file->f_path.dentry;

	if (!dent || !dent->d_parent || !dent->d_parent->d_inode)
		return -EINVAL;

	snp = kzalloc(sizeof(*snp), GFP_KERNEL);
	if (!snp)
		return -ENOMEM;

	file->private_data = snp;

	return single_open(file, ptype_seq_show, snp);
}