void mark_page_dirty_in_slot(struct kvm *kvm, struct kvm_memory_slot *memslot,
			     gfn_t gfn)
{
	if (memslot && memslot->dirty_bitmap) {
		unsigned long rel_gfn = gfn - memslot->base_gfn;
		spin_lock(&memslot->dirty_bitmap_lock);
		__set_bit_le(rel_gfn, memslot->dirty_bitmap);
		spin_unlock(&memslot->dirty_bitmap_lock);
	}
}