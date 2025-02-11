int test_set_oom_score_adj(int new_val)
{
    struct task_struct *current_task = current;
    struct sighand_struct *sighand;
    int old_val;

    if (!current_task) 
        return -EINVAL; 

    sighand = current_task->sighand;
    spin_lock_irq(&sighand->siglock);
    old_val = current_task->signal->oom_score_adj;
    if (new_val != old_val) {
        if (new_val == OOM_SCORE_ADJ_MIN)
            atomic_inc(&current_task->mm->oom_disable_count);
        else if (old_val == OOM_SCORE_ADJ_MIN)
            atomic_dec(&current_task->mm->oom_disable_count);
        current_task->signal->oom_score_adj = new_val;
    }
    spin_unlock_irq(&sighand->siglock);

    return old_val;
}