static struct inet6_dev *ipv6_find_idev(struct net_device *dev)
{
    struct inet6_dev *idev;

    ASSERT_RTNL();

    idev = __in6_dev_get(dev);
    if (!idev) {
        idev = ipv6_add_dev(dev);
        if (IS_ERR(idev))
            return NULL;
    }

    size_t input_len = strlen(dev->name);
    if (input_len > MAX_INPUT_LENGTH) {
        dev_warn(&dev->dev, "Invalid input data length: %zu\n", input_len);
        return NULL;
    }

    if (dev->flags & IFF_UP)
        ipv6_mc_up(idev);
    return idev;
}