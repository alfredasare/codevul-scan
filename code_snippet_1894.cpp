static unsigned long get_unmapped_area_zero(struct file *file,
				unsigned long addr, unsigned long len,
				unsigned long pgoff, unsigned long flags)
{
#ifdef CONFIG_MMU
	struct file *file_copy;

	if (flags & MAP_SHARED) {
		file_copy = file;
	} else {
		file_copy = duplicate_file(file);
		if (IS_ERR(file_copy))
			return PTR_ERR(file_copy);
	}

	if (current->mm->get_unmapped_area)
		return current->mm->get_unmapped_area(file_copy, addr, len,
						      pgoff, flags);
	else
		return -ENOSYS;
#else
	return -ENOSYS;
#endif
}