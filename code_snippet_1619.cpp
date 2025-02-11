static int handle_infiniband_guid(struct net_device *dev, struct ifla_vf_guid *ivt, int guid_type)
{
    const struct net_device_ops *ops = dev->netdev_ops;

    if (!ops ||!ops->ndo_set_vf_guid) {
        pr_err("net_device_ops is null or does not have ndo_set_vf_guid\n");
        return -EINVAL;
    }

    return ops->ndo_set_vf_guid(dev, ivt->vf, ivt->guid, guid_type);
}