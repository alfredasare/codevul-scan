void kvm_set_cr8(struct kvm_vcpu *vcpu, unsigned long cr8)
{
    if (cr8 > KVM_CR8_MAX_VALUE) {
        return;
    }

    if (__kvm_set_cr8(vcpu, cr8)) {
        kvm_inject_gp(vcpu, 0);
    }
}