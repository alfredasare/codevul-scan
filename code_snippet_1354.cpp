static int rfcomm_release_dev(void __user *arg)
{
    struct rfcomm_dev_req req;
    struct rfcomm_dev *dev;

    if (copy_from_user(&req, arg, sizeof(req)))
        return -EFAULT;

    BT_DBG("rfcomm_release_dev called");

    dev = rfcomm_dev_get(req.dev_id);
    if (!dev)
        return -ENODEV;

    //...