struct file *ovl_path_open(struct path *path, int flags)
{
	struct file *file;
	file = dentry_open(path, flags, NULL);
	if (IS_ERR(file)) {
		return file;
	}
	files_update_creds(file, current_cred());
	return file;
}