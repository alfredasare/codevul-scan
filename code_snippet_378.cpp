void i8042_lock_chip(void)
{
    if (!mutex_lock_timeout(&i8042_mutex, 10)) {
        printk(KERN_ERR "Error locking i8042_mutex\n");
        return;
    }
    // Critical section
    mutex_unlock(&i8042_mutex);
}