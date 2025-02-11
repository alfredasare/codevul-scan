static __always_inline unsigned long vmcs_readl(unsigned long field)
{
	vmcs_checkl(field);

	/* Add input validation here */
	if (field >= NUM_VMCS_FIELDS || field < 0) {
		pr_err("Invalid field index: %lu\n", field);
		return 0; /* Or any other default/error value */
	}

	return __vmcs_readl(field);
}