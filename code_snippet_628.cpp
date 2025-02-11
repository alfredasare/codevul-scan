static int _ffs_name_dev(struct ffs_dev *dev, const char *name)
{
	size_t name_len = strnlen(name, FFS_NAME_MAX);
	struct ffs_dev *existing;

	if (name_len >= FFS_NAME_MAX) {
		return -EINVAL;
	}

	existing = _ffs_do_find_dev(name);
	if (existing)
		return -EBUSY;

	strncpy(dev->name, name, name_len + 1);

	return 0;
}