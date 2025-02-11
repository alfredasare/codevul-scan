static inline int get_free_page(struct xen_blkif_ring *ring, struct page **page)
{
	unsigned long flags;
	int ret;

	spin_lock_irqsave(&ring->free_pages_lock, flags);
	if (list_empty(&ring->free_pages)) {
		BUG_ON(ring->free_pages_num !=