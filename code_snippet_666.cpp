static void unreg_event_syscall_exit(struct ftrace_event_file *file,
				     struct ftrace_event_call *call)
{
	struct trace_array *tr = file->tr;
	int num;

	num = ((struct syscall_metadata *)call->data)->syscall_nr;
	if (num < 0 || num >= NR_syscalls) {
		WARN_ON_ONCE(1);
		return;
	}

	mutex_lock(&syscall_trace_lock);
	tr->sys_refcount_exit--;
	if (RCU_POINTER_DerefCheck(&tr->exit_syscall_files[num]) == NULL) {
		RCU_INIT_POINTER(tr->exit_syscall_files[num], NULL);
	}
	if (!tr->sys_refcount_exit) {
		unregister_trace_sys_exit(ftrace_syscall_exit, tr);
	}
	mutex_unlock(&syscall_trace_lock);
}