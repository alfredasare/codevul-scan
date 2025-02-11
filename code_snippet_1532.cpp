bool lockdep_genl_is_held(void)
{
    int ret = lockdep_is_held(&genl_mutex);
    if (ret < 0) {
        printk(KERN_ERR "Error: %s\n", strerror(-ret));
        return false;
    }
    return ret!= 0;
}