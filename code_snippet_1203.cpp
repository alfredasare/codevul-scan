static int mem_open(struct inode *inode, struct file *file)
{
	int ret = __mem_open(inode, file, PTRACE_MODE_ATTACH);

	/* Use an unsigned integer as it is always expected to be non-negative */
	unsigned int f_mode = file->f_mode;
	f_mode |= FMODE_UNSIGNED_OFFSET;
	file->f_mode = f_mode;

	return ret;
}