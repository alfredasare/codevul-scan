int rtnl_af_register(struct rtnl_af_ops *ops)
{
    int err = 0;
    int temp;

    rtnl_lock();
    temp = __rtnl_af_register(ops);
    rtnl_unlock();
    err = temp;
    return err;
}