struct mm_struct *mm_for_maps(struct task_struct *task)
{
    struct mm_struct *mm;
    int err;

    err = mutex_lock_killable(&task->signal->cred_guard_mutex);
    if (err)
        return ERR_PTR(err);

    mm = get_task_mm(task);
    if (!mm) {
        mm = ERR_PTR(-EFAULT);
        goto out;
    }

    if (mm!= current->mm &&
          !ptrace_may_access(task, PTRACE_MODE_READ)) {
        mmput(mm);
        mm = ERR_PTR(-EACCES);
    }

out:
    mutex_unlock(&task->signal->cred_guard_mutex);

    return mm;
}