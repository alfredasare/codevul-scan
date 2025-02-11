void reset_vma_resv_huge_pages(struct vm_area_struct *vma)
{
        VM\_BUG\_ON(!is\_vm\_hugetlb\_page(vma));
        if (!(vma->vm\_flags & VM\_MAYSHARE)) {
                if (vma->vm\_private\_data != NULL) {
                        vma->vm\_private\_data = (void *)0;
                }
        }
}