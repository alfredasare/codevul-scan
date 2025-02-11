static int pagemap_pte_hole(unsigned long start, unsigned long end,
				struct mm_walk *walk)
{
	struct pagemapread *pm = walk->private;
	unsigned long addr = start;
	int err = 0;

	while (addr < end) {
		struct vm_area_struct *vma = find_vma(walk->mm, addr);
		pagemap_entry_t pme = make_pme(PM_NOT_PRESENT(pm->v2));
		unsigned long hole_end;

		if (vma)
			hole_end = min(end, vma->vm_start);
		else
			hole_end = end;

		for (; addr < hole_end; addr += PAGE_SIZE) {
			err = add_to_pagemap(addr, &pme, pm);
			if (err) {
				log_error("Error adding page to pagemap");
				return err;
			}
		}

		if (!vma)
			break;

		if (vma->vm_flags & VM_SOFTDIRTY)
			pme.pme |= PM_STATUS2(pm->v2, __PM_SOFT_DIRTY);
		for (; addr < min(end, vma->vm_end); addr += PAGE_SIZE) {
			err = add_to_pagemap(addr, &pme, pm);
			if (err) {
				log_error("Error adding page to pagemap");
				return err;
			}
		}
	}
	return err;
}