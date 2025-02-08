asmlinkage int arm_syscall(int no, struct pt_regs *regs)
{
	struct thread_info *thread = current_thread_info();
	siginfo_t info;

	if ((no >> 16) != (__ARM_NR_BASE>> 16))
		return bad_syscall(no, regs);

	switch (no & 0xffff) {
	case 0: /* branch through 0 */
		info.si_signo = SIGSEGV;
		info.si_errno = 0;
		info.si_code  = SEGV_MAPERR;
		info.si_addr  = NULL;

		arm_notify_die("branch through zero", regs, &info, 0, 0);
		return 0;

	case NR(breakpoint): /* SWI BREAK_POINT */
		regs->ARM_pc -= thumb_mode(regs) ? 2 : 4;
		ptrace_break(current, regs);
		return regs->ARM_r0;

	/*
	 * Flush a region from virtual address 'r0' to virtual address 'r1'
	 * _exclusive_.  There is no alignment requirement on either address;
	 * user space does not need to know the hardware cache layout.
	 *
	 * r2 contains flags.  It should ALWAYS be passed as ZERO until it
	 * is defined to be something else.  For now we ignore it, but may
	 * the fires of hell burn in your belly if you break this rule. ;)
	 *
	 * (at a later date, we may want to allow this call to not flush
	 * various aspects of the cache.  Passing '0' will guarantee that
	 * everything necessary gets flushed to maintain consistency in
	 * the specified region).
	 */
	case NR(cacheflush):
		return do_cache_op(regs->ARM_r0, regs->ARM_r1, regs->ARM_r2);

	case NR(usr26):
		if (!(elf_hwcap & HWCAP_26BIT))
			break;
		regs->ARM_cpsr &= ~MODE32_BIT;
		return regs->ARM_r0;

	case NR(usr32):
		if (!(elf_hwcap & HWCAP_26BIT))
			break;
		regs->ARM_cpsr |= MODE32_BIT;
 		return regs->ARM_r0;
 
 	case NR(set_tls):
		thread->tp_value = regs->ARM_r0;
 		if (tls_emu)
 			return 0;
 		if (has_tls_reg) {
			asm ("mcr p15, 0, %0, c13, c0, 3"
				: : "r" (regs->ARM_r0));
		} else {
			/*
			 * User space must never try to access this directly.
			 * Expect your app to break eventually if you do so.
			 * The user helper at 0xffff0fe0 must be used instead.
			 * (see entry-armv.S for details)
			 */
			*((unsigned int *)0xffff0ff0) = regs->ARM_r0;
		}
		return 0;

#ifdef CONFIG_NEEDS_SYSCALL_FOR_CMPXCHG
	/*
	 * Atomically store r1 in *r2 if *r2 is equal to r0 for user space.
	 * Return zero in r0 if *MEM was changed or non-zero if no exchange
	 * happened.  Also set the user C flag accordingly.
	 * If access permissions have to be fixed up then non-zero is
	 * returned and the operation has to be re-attempted.
	 *
	 * *NOTE*: This is a ghost syscall private to the kernel.  Only the
	 * __kuser_cmpxchg code in entry-armv.S should be aware of its
	 * existence.  Don't ever use this from user code.
	 */
	case NR(cmpxchg):
	for (;;) {
		extern void do_DataAbort(unsigned long addr, unsigned int fsr,
					 struct pt_regs *regs);
		unsigned long val;
		unsigned long addr = regs->ARM_r2;
		struct mm_struct *mm = current->mm;
		pgd_t *pgd; pmd_t *pmd; pte_t *pte;
		spinlock_t *ptl;

		regs->ARM_cpsr &= ~PSR_C_BIT;
		down_read(&mm->mmap_sem);
		pgd = pgd_offset(mm, addr);
		if (!pgd_present(*pgd))
			goto bad_access;
		pmd = pmd_offset(pgd, addr);
		if (!pmd_present(*pmd))
			goto bad_access;
		pte = pte_offset_map_lock(mm, pmd, addr, &ptl);
		if (!pte_present(*pte) || !pte_write(*pte) || !pte_dirty(*pte)) {
			pte_unmap_unlock(pte, ptl);
			goto bad_access;
		}
		val = *(unsigned long *)addr;
		val -= regs->ARM_r0;
		if (val == 0) {
			*(unsigned long *)addr = regs->ARM_r1;
			regs->ARM_cpsr |= PSR_C_BIT;
		}
		pte_unmap_unlock(pte, ptl);
		up_read(&mm->mmap_sem);
		return val;

		bad_access:
		up_read(&mm->mmap_sem);
		/* simulate a write access fault */
		do_DataAbort(addr, 15 + (1 << 11), regs);
	}
#endif

	default:
		/* Calls 9f00xx..9f07ff are defined to return -ENOSYS
		   if not implemented, rather than raising SIGILL.  This
		   way the calling program can gracefully determine whether
		   a feature is supported.  */
		if ((no & 0xffff) <= 0x7ff)
			return -ENOSYS;
		break;
	}
#ifdef CONFIG_DEBUG_USER
	/*
	 * experience shows that these seem to indicate that
	 * something catastrophic has happened
	 */
	if (user_debug & UDBG_SYSCALL) {
		printk("[%d] %s: arm syscall %d\n",
		       task_pid_nr(current), current->comm, no);
		dump_instr("", regs);
		if (user_mode(regs)) {
			__show_regs(regs);
			c_backtrace(regs->ARM_fp, processor_mode(regs));
		}
	}
#endif
	info.si_signo = SIGILL;
	info.si_errno = 0;
	info.si_code  = ILL_ILLTRP;
	info.si_addr  = (void __user *)instruction_pointer(regs) -
			 (thumb_mode(regs) ? 2 : 4);

	arm_notify_die("Oops - bad syscall(2)", regs, &info, no, 0);
	return 0;
}
