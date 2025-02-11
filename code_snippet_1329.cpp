int kvm_arm_vcpu_arch_has_attr(struct kvm_vcpu *vcpu, struct kvm_device_attr *attr)
{
	if (!attr || (attr->group != KVM_ARM_VCPU_PMU_V3_CTRL && attr->group != KVM_ARM_VCPU_TIMER_CTRL)) {
		pr_err("Invalid input: attr cannot be NULL or an unsupported group\n");
		return -EINVAL;
	}

	switch (attr->group) {
	case KVM_ARM_VCPU_PMU_V3_CTRL:
		return kvm_arm_pmu_v3_has_attr(vcpu, attr);
	case KVM_ARM_VCPU_TIMER_CTRL:
		return kvm_arm_timer_has_attr(vcpu, attr);
	default:
		pr_debug("Unreachable statement due to input validation\n");
		return -ENXIO;
	}
}