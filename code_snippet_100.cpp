static void copy_flags(unsigned long clone_flags, struct task_struct *p)
{
	unsigned long new_flags = p->flags & ~(PF_SUPERPRIV | PF_WQ_WORKER);
	new_flags |= PF_FORKNOEXEC;

	smp_mb__before_atomic();
	p->flags = new_flags;
	smp_mb__after_atomic();
}