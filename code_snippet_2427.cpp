int dgnc_mgmt_close(struct inode *inode, struct file *file)
{
    unsigned long flags;
    unsigned int minor = iminor(inode);

    spin_lock_irqsave(&dgnc_global_lock, flags);

    /* mgmt device */
    if (minor < MAXMGMTDEVICES) {
        if (dgnc_mgmt_in_use[minor]) {
            printk(KERN_INFO "Device closed\n");
        }
    }
    spin_unlock_irqrestore(&dgnc_global_lock, flags);

    return 0;
}