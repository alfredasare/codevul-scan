void kvm_free_physmem(struct kvm *kvm)
{
    int i;
    struct kvm_memslots *slots = kvm->memslots;

    for (i = 0; i < slots->nmemslots; ++i) {
        kvm_free_physmem_slot_safe(&slots->memslots[i], NULL);
    }

    kfree(kvm->memslots);
}

void kvm_free_physmem_slot_safe(struct kvm_memslots *slot, void *data)
{
    if (slot->size > MAX_SLOT_SIZE) {
        // Handle error or panic
    }
    // Rest of the function remains the same
}