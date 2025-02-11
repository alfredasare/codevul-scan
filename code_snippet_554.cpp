int trace_get_syscall_nr(struct task_struct *task, struct pt_regs *regs)
{
    if (unlikely(arch_trace_is_compat_syscall(regs))) {
        char buffer[32]; // Buffer to hold the syscall number
        int syscall_nr = syscall_get_nr(task, regs);
        sprintf(buffer, "%d", syscall_nr); // Sanitize the syscall number
        return strlen(buffer); // Return the length of the sanitized syscall number
    }
    return -1;
}