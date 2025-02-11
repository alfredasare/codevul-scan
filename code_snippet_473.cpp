void kvm_ioapic_calculate_eoi_exitmap(struct kvm_vcpu *vcpu,
				     u64 *eoi_exit_bitmap)
{
    struct kvm_ioapic *ioapic = vcpu->kvm->arch.vioapic;
    union kvm_ioapic_redirect_entry *e;
    struct kvm_lapic_irq irqe;
    int index;

    spin_lock(&ioapic->lock);
    for (index = 0; index < IOAPIC_NUM_PINS && index < sizeof(ioapic->redirtbl) / sizeof(ioapic->redirtbl[0]); index++) {
        e = &ioapic->redirtbl[index];
        if (!e->fields.mask &&
            (e->fields.trig_mode == IOAPIC_LEVEL_TRIG ||
             kvm_irq_has_notifier(ioapic->kvm, KVM_IRQCHIP_IOAPIC, index))) {
            irqe.dest_id = e->fields.dest_id;
            irqe.vector = e->fields.vector;
            irqe.dest_mode = e->fields.dest_mode;
            irqe.delivery_mode = e->fields.delivery_mode << 8;
            if (eoi_exit_bitmap!= NULL) {
                kvm_calculate_eoi_exitmap(vcpu, &irqe, eoi_exit_bitmap);
            } else {
                // Handle invalid input or out-of-bounds access
                printk(KERN_ERR "Invalid input or out-of-bounds access\n");
            }
        }
    }
    spin_unlock(&ioapic->lock);
}