static int kvm_read_hva(void *data, const void __user *hva, size_t len)
{
	return copy_from_user(data, hva, len < PAGE_SIZE ? len : PAGE_SIZE);
}