static void svm_fpu_activate(struct kvm_vcpu *vcpu)
{
    struct vcpu_svm *svm = to_svm(vcpu);

    struct nm_vector sanitized_vector;

    // Sanitize NM_VECTOR before accessing its contents
    memcpy(&sanitized_vector, &svm->nm_vector, sizeof(sanitized_vector));

    clr_exception_intercept(svm, &sanitized_vector);

    svm->vcpu.fpu_active = 1;
    update_cr0_intercept(svm);
}