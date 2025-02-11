static vm_fault_t hugetlb_vm_op_fault(struct vm_fault *vmf)
{
    if (vmf->vma->vm_flags & VM_HUGETLB) {
        printk(KERN_WARNING "hugetlb: fault at %lx\n", (unsigned long)vmf->address);
    }
    return 0;
}