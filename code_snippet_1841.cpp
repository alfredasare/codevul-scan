static int get_user_dscr(struct task_struct *task, unsigned long *data, struct cred *cred)
{
    if (!capable(CAP_SYS_ADMIN))
        return -EPERM;

    *data = task->thread.dscr;
    return 0;
}