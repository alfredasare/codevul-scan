#include <linux/mutex.h>

static DEFINE_MUTEX(memslot_mutex); /* Define a mutex for memslot operations */

void mark_page_dirty_in_slot(struct kvm *kvm, struct kvm_memory_slot *memslot,
                             gfn_t gfn)
{
	if (memslot && memslot->dirty_bitmap) {
		mutex_lock(&memslot_mutex); /* Acquire the mutex before accessing memslot */

		unsigned long rel_gfn = gfn - memslot->base_gfn;