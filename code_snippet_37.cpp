static int handle_xrstors(struct kvm_vcpu *vcpu)
{
#ifdef CONFIG_KVM_HW_EXCEPTIONS
	u64 msr;
	int ret;

	ret = kvm_check_extension(vcpu, KVM_CAP_XSAVES_EXTRA_STATE,