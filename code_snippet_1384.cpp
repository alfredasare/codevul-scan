void flush_tlb_current_task(void)
{
    struct mm_struct *mm = current->mm;
    rwlock_t flush_lock = RWLOCK_UNLOCKED;

    preempt_disable();

    rwlock_write_lock(&flush_lock);
    count_vm_tlb_event(NR_TLB_LOCAL_FLUSH_ALL);
    local_flush_tlb();
    trace_tlb_flush(TLB_LOCAL_SHOOTDOWN, TLB_FLUSH_ALL);

    if (cpumask_any_but(mm_cpumask(mm), smp_processor_id()) < nr_cpu_ids)
        flush_tlb_others(mm_cpumask(mm), mm, 0UL, TLB_FLUSH_ALL);

    rwlock_write_unlock(&flush_lock);
    preempt_enable();
}