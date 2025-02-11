static void copy_flags(unsigned long clone_flags, struct task_struct *p)
{
    unsigned long new_flags = p->flags;

    if (clone_flags & ~(PF_SUPERPRIV | PF_WQ_WORKER)) {
        return;
    }

    new_flags &= ~(PF_SUPERPRIV | PF_WQ_WORKER);
    new_flags |= PF_FORKNOEXEC;
    p->flags = new_flags;
}