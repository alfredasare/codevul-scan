void flush_thread(void)
{
 discard_lazy_cpu_state();

#ifdef CONFIG_HAVE_HW_BREAKPOINT
 flush_ptrace_hw_breakpoint(current);
#else /* CONFIG_HAVE_HW_BREAKPOINT */
 clear_debug_registers(&current->thread);
#endif /* CONFIG_HAVE_HW_BREAKPOINT */
}