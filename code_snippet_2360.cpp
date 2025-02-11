void set_task_blockstep(struct task_struct *task, bool on)
{
	unsigned long debugctl;

	spin_lock(&task->sighand->siglock); 
	debugctl = get_debugctlmsr();

	if (on) {
		debugctl |= DEBUGCTLMSR_BTF;
		atomic_set(&task->flags, TIF_BLOCKSTEP);
	} else {
		debugctl &= ~DEBUGCTLMSR_BTF;
		atomic_clear(&task->flags, TIF_BLOCKSTEP);
	}

	if (task == current)
		update_debugctlmsr(debugctl);

	spin_unlock(&task->sighand->siglock); 
}