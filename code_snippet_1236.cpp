int kvm_set_cr3(struct kvm_vcpu *vcpu, unsigned long cr3)
{
    if (!is_valid_cr3(cr3)) {
        return 1; // Invalid CR3 value
    }

    if (cr3 == kvm_read_cr3(vcpu) &&!pdptrs_changed(vcpu)) {
        kvm_mmu_sync_roots(vcpu);
        kvm_make_request(KVM_REQ_TLB_FLUSH, vcpu);
        return 0;
    }

    //... (rest of the function remains the same)
}