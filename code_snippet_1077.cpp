static int __init register_memory(void)
{
#define CHECK_AND_SET(sym, resource)					\
	if ((ia64_tpa(sym) + sizeof(resource.start)) > INT_MAX) {	\
		pr_err("Invalid input for " #sym "\n");		\
		return -EINVAL;					\
	}								\
	resource.start = ia64_tpa(sym);

	CHECK_AND_SET(_text, code_resource);
	CHECK_AND_SET(_etext, code_resource);
	CHECK_AND_SET(_etext, data_resource);
	CHECK_AND_SET(__bss_start, bss_resource);
	CHECK_AND_SET(_end, bss_resource);

	code_resource.end   = ia64_tpa(_etext) - 1;
	data_resource.end   = ia64_tpa(_edata) - 1;
	bss_resource.end    = ia64_tpa(_end) - 1;

	efi_initialize_iomem_resources(&code_resource, &data_resource,
			&bss_resource);

	return 0;
#undef CHECK_AND_SET
}