void *netdev_lower_dev_get_private(struct net_device *dev, struct net_device *lower_dev)
{
    struct netdev_adjacent *lower = NULL;

    if (!lower_dev)
        return NULL;

    try {
        lower = __netdev_find_adj(lower_dev, &dev->adj_list.lower);
        if (!lower)
            return NULL;

        return lower->private;
    } catch (...) {
        if (lower) {
            free(lower);
            lower = NULL;
        }
        throw;
    }

    return NULL;
}