static int pid_numa_maps_open(struct inode *inode, struct file *file)
{
	int error;

	error = numa_maps_open(inode, file, &proc_pid_numa_maps_op);
	if (error)
		return error;

	get_pid(file->f_path.dentry->d_inode);
	return 0;
}