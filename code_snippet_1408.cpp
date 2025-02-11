static int kvm_vm_ioctl_set_memory_region(struct kvm *kvm,
					  struct kvm_userspace_memory_region *mem)
{
	if (mem->slot >= KVM_USER_MEM_SLOTS || mem->slot < 0)
		return -EINVAL;

	return kvm_set_memory_region(kvm, mem);
}