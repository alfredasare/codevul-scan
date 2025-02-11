int kvm_read_guest_atomic(struct kvm *kvm, gpa_t gpa, void *data,
                           unsigned long len)
{
	int r;
	unsigned long addr;
	gfn_t gfn = gpa >> PAGE_SHIFT;
	int offset = offset_in_page(gpa);

	if (!access_ok(VERIFY_READ, data, len))
		return -EFAULT;

	addr = gfn_to_hva(kvm, gfn);
	if (kvm_is_error_hva(addr))
		return -EFAULT;

	r = copy_from_user(data, (void __user *)addr + offset, len);
	if (r)
		return -EFAULT;

	return 0;
}