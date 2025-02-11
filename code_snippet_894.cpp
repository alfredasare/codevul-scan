static void usbfs_decrease_memory_usage(unsigned amount)
{
    unsigned current_usage = atomic_read(&usbfs_memory_usage);
    if (current_usage >= amount) {
        atomic_sub(amount, &usbfs_memory_usage);
    } else {
        printk(KERN_WARNING "usbfs: attempted to decrease memory usage by %u, but current usage is %u\n",
               amount, current_usage);
    }
}