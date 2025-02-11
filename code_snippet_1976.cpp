static struct dentry *__lookup_hash(const struct qstr *name, struct dentry *base, unsigned int flags)
{
	struct dentry *dentry = lookup_dcache(name, base, flags);
	struct path path;

	if (dentry)
		return dentry;

	dentry = d_alloc(base, name);
	if (unlikely(!dentry))
		return ERR_PTR(-ENOMEM);

	if (d_revalidate(dentry, &path)) {
		dput(dentry);
		return ERR_PTR(-ESTALE);
	}

	return lookup_real(path.dentry->d_inode, dentry, flags);
}