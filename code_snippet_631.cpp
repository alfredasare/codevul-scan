static inline void preempt_conditional_cli(struct pt_regs *regs, atomic_t *preempt_count)
{
	if (regs->flags & X86_EFLAGS_IF) {
		local_irq_disable();
		smp_mb__after_atomic();
		atomic_dec(preempt_count);
	} else {
		smp_mb__before_atomic();
		atomic_dec(preempt_count);
		local_irq_disable();
	}
}