static struct page *no_page_table(struct vm_area_struct *vma,
	unsigned int flags)
{
	if ((flags & FOLL_DUMP) && (!vma->vm_ops ||!vma->vm_ops->fault)) {
		if (flags >= FOLL_DUMP || flags < 0) {
			return ERR_PTR(-EFAULT);
		}
	}
	return NULL;
}