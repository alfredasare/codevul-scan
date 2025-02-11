int is_file_shm_hugepages(struct file *file)
{
	if (!file || !file->f_op || !file->private_data)
		return 0;

	return file->f_op == &shm_file_operations_huge;
}