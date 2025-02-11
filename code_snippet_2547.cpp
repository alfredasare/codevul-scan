void set_task_blockstep(struct task_struct *task, bool on)
{
	unsigned long debugctl;
	bool is_current_task = (task == current);
	mutex_lock(&task_debugctl_mutex);

	local_irq_disable();
	debugctl = get_debugctlmsr();
	if (on && is_current_task) {
		debugctl |= DEBUGCTLMSR_BTF;
		set_tsk_thread_flag(task, TIF_BLOCKSTEP);
	} else if (!on && is_current_task) {
		debugctl &= ~DEBUGCTLMSR_BTF;
		clear_tsk_thread_flag(task, TIF_BLOCKSTEP);
	}

	if (is_current_task)
		update_debugctlmsr(debugctl);
	local_irq_enable();
	mutex_unlock(&task_debugctl_mutex);
}