static void do_error_trap(struct pt_regs *regs, long error_code, char *str,
			  unsigned long trapnr, int signr)
{
	siginfo_t info;

	RCU_LOCKDEP_WARN(!rcu_is_watching(), "entry code didn't wake RCPU");

	/* Perform the user mode check before calling notify_die */
	if (user_mode(regs)) {
		/* If it's in user mode, handle it differently */
		...
	} else {
		if (fixup_bug(regs, trapnr))
			return;

		if (notify_die(DIE_TRAP, str, regs, error_code, trapnr, signr) !=
				NOTIFY_STOP) {
			cond_local_irq_enable(regs);
			do_trap(trapnr, signr, str, regs, error_code,
				fill_trap_info(regs, signr, trapnr, &info));
		}
	}
}