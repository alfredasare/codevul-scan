static void fsl_emb_pmu_enable(struct pmu *pmu)
{
    struct cpu_hw_events *cpuhw;
    unsigned long flags;
    struct cpu_hw_events *local_cpuhw;

    local_irq_save(flags);
    local_cpuhw = __get_cpu_var(cpu_hw_events);
    if (local_cpuhw == NULL || local_cpuhw->disabled)
        goto out;

    cpuhw = local_cpuhw;
    cpuhw->disabled = 0;
    ppc_set_pmu_inuse(cpuhw->n_events!= 0);

    if (cpuhw->n_events > 0) {
        mtpmr(PMRN_PMGC0, PMGC0_PMIE | PMGC0_FCECE);
        isync();
    }

out:
    local_irq_restore(flags);
}