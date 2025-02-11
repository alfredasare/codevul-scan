static void svm_cpuid_update(struct kvm_vcpu *vcpu)
{
	struct vcpu_svm *svm = to_svm(vcpu);
	int expected, desired;

	expected = !svm->nrips_enabled;
	desired = guest_cpuid_has_nrips(&svm->vcpu);

	/* Update nrips enabled cache atomically */
	while (!atomic_cmpxchg(&svm->nrips_enabled, &expected, desired)) {
		expected = !svm->nrips_enabled;
		desired = guest_cpuid_has_nrips(&svm->vcpu);
	}
}