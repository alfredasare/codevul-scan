static void __dma_remap(struct page *page, size_t size, pgprot_t prot)
{
	phys_addr_t start = page_phys(page);
	unsigned long end = start + size;

	apply_to_page_range(&init_mm, (unsigned long)start, size, __dma_update_pte, &prot);
	flush_tlb_kernel_range((unsigned long)start, (unsigned long)end);
}