static int vhost_net_release(struct inode *inode, struct file *f)
{
    struct vhost_net *n = f->private_data;
    struct socket *tx_sock;
    struct socket *rx_sock;

    vhost_net_stop(n, &tx_sock, &rx_sock);
    if (n->dev)
        vhost_net_flush_safe(n);
    vhost_dev_stop(&n->dev);
    vhost_dev_cleanup(&n->dev, false);
    vhost_net_vq_reset(n);
    if (tx_sock)
        fput(tx_sock->file);
    if (rx_sock)
        fput(rx_sock->file);
    /* Make sure no callbacks are outstanding */
    synchronize_rcu_bh();
    kfree(n->dev.vqs);
    kfree(n);
    return 0;
}

void vhost_net_flush_safe(struct vhost_net *n)
{
    // Flush the buffers safely
    //...
}