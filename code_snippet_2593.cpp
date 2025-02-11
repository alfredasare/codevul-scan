__gfn_to_pfn_memslot(struct kvm_memory_slot *slot, gfn_t gfn, bool atomic,
		     bool *async, bool write_fault, bool *writable)
{
	unsigned long addr = __gfn_to_hva_many(slot, gfn, NULL, write_fault);

	if (addr == KVM_HVA_ERR_RO_BAD)
		return KVM_PFN_ERR_RO_FAULT;

	if (kvm_is_error_hva(addr))
		return KVM_PFN_NOSLOT;

	/* Validate the writable pointer before using it */
	if (writable && memslot_is_readonly(slot)) {
		if (!writable) {
			return KVM_PFN_ERR_INVALID_POINTER;
		}
		*writable = false;
		writable = NULL;
	}

	return hva_to_pfn(addr, atomic, async, write_fault,
			  writable);
}