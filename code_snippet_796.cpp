static int ipip6_tunnel_init(struct net_device *dev)
{
    struct ip_tunnel *tunnel = netdev_priv(dev);

    tunnel->dev = dev;
    if (strlen(dev->name) > 20) {
        return -EINVAL;
    }
    strcpy(tunnel->parms.name, dev->name);

    char saddr_str[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6, &tunnel->parms.iph.saddr, saddr_str, sizeof(saddr_str));
    dev->dev_addr = kstrdup(saddr_str, GFP_KERNEL);
    if (!dev->dev_addr)
        return -ENOMEM;

    char bcast_str[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6, &tunnel->parms.iph.daddr, bcast_str, sizeof(bcast_str));
    dev->broadcast = kstrdup(bcast_str, GFP_KERNEL);
    if (!dev->broadcast)
        return -ENOMEM;

    ipip6_tunnel_bind_dev(dev);
    dev->tstats = alloc_percpu(struct pcpu_tstats);
    if (!dev->tstats)
        return -ENOMEM;

    return 0;
}