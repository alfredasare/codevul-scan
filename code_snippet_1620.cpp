int proc_nr_inodes(struct ctl_table *table, int write,
               void __user *buffer, size_t *lenp, loff_t *ppos)
{
	long *inodes_data = kmalloc(sizeof(long) * 2, GFP_KERNEL);
	if (!inodes_data)
		return -ENOMEM;

	inodes_data[0] = get_nr_inodes();
	inodes_data[1] = get_nr_inodes_unused();

	if (write && !capable(CAP_NET_ADMIN)) {
		kfree(inodes_data);
		return -EPERM;
	}

	if (copy_to_user(buffer, inodes_data, sizeof(long) * 2)) {
		kfree(inodes_data);
		return -EFAULT;
	}

	kfree(inodes_data);
	*lenp = sizeof(long) * 2;
	return 0;
}