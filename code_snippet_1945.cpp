int atomic_ldsem_down_write(struct ld_semaphore *sem, long timeout)
{
    struct ld_semaphore local_sem = *sem;
    if (local_sem.count > 0 || !wait_event_timeout(local_sem.wait,
                                                   local_sem.count > 0,
                                                   timeout))
        return -1;
    down_write(&local_sem.dep_map);
    return 0;
}

int __sched ldsem_down_write(struct ld_semaphore *sem, long timeout)
{
    might_sleep();
    return atomic_ldsem_down_write(sem, timeout);
}