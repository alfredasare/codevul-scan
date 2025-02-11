static void __dma_remap(struct page *page, size_t size, pgprot_t prot)
{
    unsigned long start = (unsigned long) page_address(page);
    unsigned long end = start + size;

    if (start >= (unsigned long)page->index * PAGE_SIZE && start + size <= (unsigned long)(page->index + 1) * PAGE_SIZE)
        apply_to_page_range(&init_mm, start, size, __dma_update_pte, &prot);

    flush_tlb_kernel_range(start, end);
}