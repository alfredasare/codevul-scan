static void tun_free_netdev(struct net_device *dev)
{
    struct tun_struct *tun = NULL;

    tun = netdev_priv(dev);

    if (tun != NULL) {
        BUG_ON(!test_bit(SOCK_EXTERNALLY_ALLOCATED, &tun->socket.flags));
        sk_release_kernel(tun->socket.sk);
    }
}