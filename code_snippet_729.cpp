void kvm_define_shared_msr(unsigned slot, u32 msr)
{
	if (slot >= ARRAY_SIZE(shared_msrs_global.msrs)) {
		pr_err("Error: Invalid shared MSR slot index\n");
		return;
	}

	shared_msrs_global.msrs[slot] = msr;
	smp_wmb();
}