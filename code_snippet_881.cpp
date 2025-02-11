static int __net_init ipip_init_net(struct net *net)
{
    struct ipip_net *ipn = net_generic(net, ipip_net_id);
    int err;

    ipn->tunnels[0] = ipn->tunnels_wc;
    ipn->tunnels[1] = ipn->tunnels_l;
    ipn->tunnels[2] = ipn->tunnels_r;
    ipn->tunnels[3] = ipn->tunnels_r_l;

    ipn->fb_tunnel_dev = alloc_netdev(sizeof(struct ip_tunnel),
                                     "tunl0",
                                     ipip_tunnel_setup);
    if (!ipn->fb_tunnel_dev) {
        err = -ENOMEM;
        goto err_alloc_dev;
    }

    err = dev_net_set(ipn->fb_tunnel_dev, net);
    if (err) {
        goto err_set_dev_net;
    }

    err = ipip_fb_tunnel_init(ipn->fb_tunnel_dev);
    if (err)
        goto err_init_tunnel;

    err = register_netdev(ipn->fb_tunnel_dev);
    if (err)
        goto err_register_dev;

    return 0;

err_register_dev:
    unregister_netdev(ipn->fb_tunnel_dev);
err_init_tunnel:
    ipip_fb_tunnel_free(ipn->fb_tunnel_dev);
err_set_dev_net:
    ipn->fb_tunnel_dev = NULL;
err_alloc_dev:
    return err;
}