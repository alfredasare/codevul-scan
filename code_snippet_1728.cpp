void kvm_vcpu_request_scan_ioapic(struct kvm *kvm)
{
    struct kvm_ioapic *ioapic = kvm->arch.vioapic;

    if (!ioapic ||!ioapic->size) {
        return;
    }

    for (int i = 0; i < ioapic->size; i++) {
        ioapic->redir[i].redir_type = KVM_IOAPIC_REDIR_TYPE_IRQ;
        //...
    }

    kvm_make_scan_ioapic_request(kvm);
}