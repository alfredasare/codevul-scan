static int get_wcr(struct kvm_vcpu *vcpu, const struct sys_reg_desc *rd,
		   const struct kvm_one_reg *reg, void __user *uaddr)
{
	__u64 *r = &vcpu->arch.vcpu_debug_state.dbg_wcr[rd->reg];
	size_t size = KVM_REG_SIZE(reg->id);

	if (uaddr == NULL || size == 0 ||
	    __copy_check_size(uaddr, size) ||
	    (size_t)copy_to_user(uaddr, r, size) != size)
		return -EFAULT;

	return 0;
}