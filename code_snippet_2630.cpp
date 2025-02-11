static inline struct page * __pure pgv\_to\_page(void \*addr)
{
	if (is\_vmalloc\_addr(addr))
		return vmalloc\_to\_page((unsigned long)addr);
	else if (isValidPhysicalAddress(addr))
		return phys\_to\_page((phys\_addr\_t)addr);
	else
		return NULL;
}