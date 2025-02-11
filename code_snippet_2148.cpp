static int pid_numa_maps_open(struct inode *inode, struct file *file)
{
    int ret = numa_maps_open(inode, file, &proc_pid_numa_maps_op);

    if (ret < 0) {
        printk(KERN_INFO "Error opening pid numa maps\n");
        return -EFAULT;
    }

    return ret;
}