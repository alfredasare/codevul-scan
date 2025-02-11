static int mmap_ureg(struct vm_area_struct *vma, struct qib_devdata *dd,
		     u64 ureg)
{
	unsigned long phys;
	unsigned long sz;
	int ret;

	sz = dd->flags & QIB_HAS_HDRSUPP ? 2 * PAGE_SIZE : PAGE_SIZE;

	/*
	 * This is real hardware, so use io_remap.  This is the mechanism
	 * for the user process to update the head registers for their ctxt
	 * in the chip.
	 */
	phys = dd->physaddr + ureg;
	if ((vma->vm_end - vma->vm_start) > sz) {
		qib_devinfo(dd->pcidev,
			"FAIL mmap userreg: reqlen %lx > PAGE\n",
			vma->vm_end - vma->vm_start);
		ret = -EFAULT;
	} else {
		vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);

		vma->vm_flags |= VM_DONTCOPY | VM_DONTEXPAND;
		ret = remap_pfn_range(vma, vma->vm_start,
				     phys >> PAGE_SHIFT,
				     vma->vm_end - vma->vm_start,
				     vma->vm_page_prot);
	}
	return ret;
}