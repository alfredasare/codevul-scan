static void smp_task_timedout(struct timer_list *t)
{
    struct sas_task_slow *slow = from_timer(slow, t, timer);
    struct sas_task *task = slow->task;
    unsigned long flags;

    spin_lock_irqsave(&task->task_state_lock, flags);

    // Check if the task has already been completed or aborted
    if (task->task_state_flags & (SAS_TASK_STATE_DONE | SAS_TASK_STATE_ABORTED)) {
        spin_unlock_irqrestore(&task->task_state_lock, flags);
        return;
    }

    // Complete the task only once
    if (!(task->task_state_flags & SAS_TASK_STATE_DONE)) {
        task->task_state_flags |= SAS_TASK_STATE_DONE;
        spin_unlock_irqrestore(&task->task_state_lock, flags);
    } else {
        spin_unlock_irqrestore(&task->task_state_lock, flags);
    }

    complete(&task->slow_task->completion);
}