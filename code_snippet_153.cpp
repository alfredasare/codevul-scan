static u64 kvm_dr6_fixed(struct kvm_vcpu *vcpu)
{
    char buffer[256]; // Fixed-size buffer
    u64 fixed = DR6_FIXED_1;

    if (!guest_cpuid_has_rtm(vcpu)) {
        fixed |= DR6_RTM;
        snprintf(buffer, sizeof(buffer), "Fixed value: 0x%" PRIx64, fixed);
    } else {
        snprintf(buffer, sizeof(buffer), "RTM enabled");
    }

    return fixed;
}