static int udf\_rmdir(struct inode *dir, struct dentry *dentry)
{
	int retval;
	struct inode *inode = dentry->d\_inode;
	struct udf\_fileident\_bh fibh;
	struct fileIdentDesc *fi, cfi;
	struct kernel\_lb\_addr tloc;
	const char *dentry\_name = dentry->d\_name.name;

	if (!dentry\_name || strlen(dentry\_name) > NAME\_MAX) {
		retval = -EINVAL;
		goto out;
	}

	retval = -ENOENT;
	fi = udf\_find\_entry(dir, &dentry->d\_name, &fibh, &cfi);
	if (!fi)
		goto out;

	// ... remaining code ...

out:
	if (fibh.sbh != fibh.ebh)
		brelse(fibh.ebh);
	brelse(fibh.sbh);

	return retval;
}