static int numa_maps_open(struct inode *inode, struct file *file,
                          const struct seq_operations *ops)
{
    size_t size = sizeof(struct numa_maps_private);
    // Validate the size parameter
    if (size < MIN_BUFFER_SIZE || size > MAX_BUFFER_SIZE) {
        return -EINVAL;
    }
    return proc_maps_open(inode, file, ops, size);
}