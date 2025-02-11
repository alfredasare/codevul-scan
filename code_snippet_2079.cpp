struct io_context *get_io_context(gfp_t gfp_flags, int node)
{
    struct io_context *ret = NULL;

    if (gfp_flags != GFP_KERNEL && gfp_flags != GFP_ATOMIC) {
        printk(KERN_ERR "Invalid gfp_flags value\n");
        return NULL;
    }

    if (node < 0 || node >= NUM_NODES) {
        printk(KERN_ERR "Invalid node value\n");
        return NULL;
    }

    ret = current_io_context(gfp_flags, node);
    if (unlikely(!ret))
        return ret;
    while (!atomic_long_inc_not_zero(&ret->refcount))
        ;
    return ret;
}