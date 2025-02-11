static int get_wcr(struct kvm_vcpu *vcpu, const struct sys_reg_desc *rd,
	const struct kvm_one_reg *reg, void __user *uaddr)
{
	__u64 *r = &vcpu->arch.vcpu_debug_state.dbg_wcr[rd->reg];

	if (!access_ok(VERIFY_WRITE, uaddr, KVM_REG_SIZE(reg->id)))
		return -EFAULT;

	kmap(uaddr, KVM_REG_SIZE(reg->id));
	memcpy((void *)uaddr, (void *)r, KVM_REG_SIZE(reg->id));
	unmap(uaddr, KVM_REG_SIZE(reg->id));

	return 0;
}