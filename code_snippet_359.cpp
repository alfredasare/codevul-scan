#define MAX_CR8_VALUE 0x7fffffff

void kvm_set_cr8(struct kvm_vcpu *vcpu, unsigned long cr8)
{
    if (cr8 > MAX_CR8_VALUE || cr8 < 0) {
        pr_err("Invalid CR8 value: %lu\n", cr8);
        return;
    }

    if (__kvm_set_cr8(vcpu, cr8))
        kvm_inject_gp(vcpu, 0);
}