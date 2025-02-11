static int get_user_dscr(struct task_struct *task, unsigned long *data)
{
    if (data < (unsigned long *)task->thread.dscr &&
        data + sizeof(unsigned long) <= (unsigned long *)task->thread.dscr + PAGE_SIZE) {
        *data = task->thread.dscr;
        return 0;
    } else {
        return -EINVAL;
    }
}