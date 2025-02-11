static void svm_cpuid_update(struct kvm_vcpu *vcpu)
{
    struct vcpu_svm *svm = to_svm(vcpu);

    /* Validate input before using it */
    if (!vcpu ||!vcpu->arch) {
        pr_err("Invalid vcpu pointer\n");
        return;
    }

    /* Update nrips enabled cache */
    svm->nrips_enabled =!!guest_cpuid_has_nrips(vcpu->arch);
}