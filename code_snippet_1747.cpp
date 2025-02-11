static unsigned long get_unmapped_area_zero(struct file *file,
					unsigned long addr, unsigned long len,
					unsigned long pgoff, unsigned long flags)
{
#ifdef CONFIG_MMU
	if (flags & MAP_SHARED) {
		struct file *file = shmem_zero_setup(NULL);
		if (IS_ERR(file)) {
			return PTR_ERR(file);
		}
		return shmem_get_unmapped_area(file, addr, len, pgoff, flags);
	} else {
		return current->mm->get_unmapped_area(file, addr, len, pgoff, flags);
	}
#else
	return -ENOSYS;
#endif
}