static struct dentry *__lookup_hash(const struct qstr *name,
				     struct dentry *base, unsigned int flags)
{
	struct dentry *dentry = lookup_dcache(name, base, flags);

	if (dentry)
		return dentry;

	if (!base ||!dentry_valid(base)) {
		return ERR_PTR(-EINVAL);
	}

	dentry = d_alloc(base, name);
	if (unlikely(!dentry))
		return ERR_PTR(-ENOMEM);

	return lookup_real(base->d_inode, dentry, flags);
}