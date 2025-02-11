int __remove_suid(struct dentry *dentry, int kill)
{
	struct iattr newattrs;
	const int valid_mask = ATTR_FORCE; /* Only ATTR_FORCE is allowed */

	if (kill & ~valid_mask) {
		pr_warn("Invalid 'kill' value: 0x%x\n", kill);
		return -EINVAL;
	}

	newattrs.ia_valid = valid_mask | kill;
	return notify_change(dentry, &newattrs);
}