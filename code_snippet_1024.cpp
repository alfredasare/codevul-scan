static void kvm_pv_kick_cpu_op(struct kvm *kvm, unsigned long flags, int apicid)
{
	if (apicid < 0 || apicid > KVM_MAX_APICIDS) {
		pr_err("Invalid APIC ID: %d\n", apicid);
		return;
	}

	struct kvm_lapic_irq lapic_irq;

	lapic_irq.shorthand = 0;
	lapic_irq.dest_mode = 0;
	lapic_irq.dest_id = apicid;

	lapic_irq.delivery_mode = APIC_DM_REMRD;
	kvm_irq_delivery_to_apic(kvm, 0, &lapic_irq, NULL);
}