version of the code:


static void svm_init_erratum_383(void)
{
	int err;
	u64 val;

	if (!static_cpu_has_bug(X86_BUG_AMD_TLB_MMATCH))