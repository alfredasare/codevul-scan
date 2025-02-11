int __sched ldsem_down_write(struct ld_semaphore *sem, long timeout)
{
    static struct mutex sem_mutex = MUTEX_INITIALIZER; // Declare and initialize mutex

    might_sleep();

    mutex_lock(&sem_mutex); // Acquire mutex
    int result = __ldsem_down_write_nested(sem, 0, timeout);
    mutex_unlock(&sem_mutex); // Release mutex

    return result;
}