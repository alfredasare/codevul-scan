static int handle_wbinvd(struct kvm_vcpu *vcpu)
{
	int ret;

	save_vcpu_state(vcpu);

	ret = kvm_emulate_wbinvd(vcpu);

	restore_vcpu_state(vcpu);

	return ret;
}

void save_vcpu_state(struct kvm_vcpu *vcpu)
{
	kvm_vcpu_get_reg(vcpu, VCPU_REGS_RIP, &vcpu->arch.rip);
	kvm_vcpu_get_reg(vcpu, VCPU_REGS_RSP, &vcpu->arch.rsp);
	// Save other necessary registers and state here
}

void restore_vcpu_state(struct kvm_vcpu *vcpu)
{
	kvm_vcpu_set_reg(vcpu, VCPU_REGS_RIP, vcpu->arch.rip);
	kvm_vcpu_set_reg