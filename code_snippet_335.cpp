static int ptrace_setsiginfo(struct task_struct *child, const kernel_siginfo_t *info)
{
    unsigned long flags;
    int error = -ESRCH;
    struct sighandler_struct *sighandler;

    if (lock_task_sighand(child, &flags)) {
        error = -EINVAL;
        if (likely(child->last_siginfo!= NULL)) {
            spin_lock_irqsave(&child->sighandler_lock, flags);
            copy_siginfo(child->last_siginfo, info);
            spin_unlock_irqrestore(&child->sighandler_lock, flags);
            error = 0;
        }
        unlock_task_sighand(child, &flags);
    }
    return error;
}