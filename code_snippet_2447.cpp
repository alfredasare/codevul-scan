static int ovl_set_timestamps(struct dentry *upperdentry, struct kstat *stat)
{
	struct iattr attr = {
		.ia_valid =
		     ATTR_ATIME | ATTR_MTIME | ATTR_ATIME_SET | ATTR_MTIME_SET,
	};

	get_ktime(&attr.ia_atime);
	get_ktime(&attr.ia_mtime);

	return notify_change(upperdentry, &attr, NULL);
}