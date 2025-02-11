static void fsl_emb_pmu_enable(struct pmu *pmu)
{
	struct cpu_hw_events *cpuhw;
	unsigned long flags;

	local_irq_save(flags);
	cpuhw = &__get_cpu_var(cpu_hw_events);
	if (!cpuhw) {
		pr_err("Error: cpuhw pointer is NULL\n");