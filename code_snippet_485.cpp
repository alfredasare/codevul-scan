void flush_thread(void)
{
    discard_lazy_cpu_state();

    size_t breakpoint_size = sizeof(current->thread.debug_regs);
    char* breakpoint_buffer = (char*)&current->thread.debug_regs;

#ifdef CONFIG_HAVE_HW_BREAKPOINT
    flush_ptrace_hw_breakpoint(current);
#else /* CONFIG_HAVE_HW_BREAKPOINT */
    set_debug_reg_defaults(&current->thread);
#endif /* CONFIG_HAVE_HW_BREAKPOINT */

    // Validate input parameters
    if (sizeof(current->thread.debug_regs) > breakpoint_buffer_size) {
        printk(KERN_ERR "Invalid breakpoint size: %zu\n");
        return;
    }
}