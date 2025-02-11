void rtnl_af_unregister(struct rtnl_af_ops *ops)
{
    if (!ops) {
        printk(KERN_ERR "rtnl_af_unregister: ops is null\n");
        return;
    }

    rtnl_lock();
    __rtnl_af_unregister(ops);
    rtnl_unlock();
}