static inline struct page * __pure pgv_to_page(void *addr)
{
    if (!is_vmalloc_addr(addr)) {
        unsigned long pfn;
        pfn = virt_to_pfn(addr);
        if (pfn_valid(pfn))
            return pfn_to_page(pfn);
    }
    return NULL;
}