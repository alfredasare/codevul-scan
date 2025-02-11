xfs_file_mmap(
	struct file	*filp,
	struct vm_area_struct *vma)
{
	if (!filp || !vma) {
		pr_err("NULL pointer access in xfs_file_mmap\n");
		return -EINVAL;
	}

	vma->vm_ops = &xfs_file_vm_ops;

	file_accessed(filp);
	return 0;
}