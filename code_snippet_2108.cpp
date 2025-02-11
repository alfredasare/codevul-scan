static int kvm_deassign_ioeventfd(struct kvm *kvm, struct kvm_ioeventfd *args)
{
	// Validate args != NULL
	if (!args) {
		pr_err("Invalid input: args is NULL\n");
		return -EINVAL;
	}

	enum kvm_bus bus_idx = ioeventfd_bus_from_flags(args->flags);

	int ret = kvm_deassign_ioeventfd_idx(kvm, bus_idx, args);

	if (bus_idx == KVM_MMIO_BUS && args->len >= 0) {
		kvm_deassign_ioeventfd_idx(kvm, KVM_FAST_MMIO_BUS, args);
	}

	return ret;
}