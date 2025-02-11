static int vhost_net_release(struct inode *inode, struct file *f)
{
	struct vhost_net *n = f->private_data;
	struct socket *tx_sock;
	struct socket *rx_sock;

	vhost_net_stop(n, &tx_sock, &rx_sock);
	vhost_net_flush(n);
	vhost_dev_stop(&n->dev);
	vhost_dev_cleanup(&n->dev, false);
	vhost_net_vq_reset(n);
	if (tx_sock) {
		rcu_assign_pointer(n->dev.tx_sock, NULL);
		fput(tx_sock->file);
	}
	if (rx_sock) {
		rcu_assign_pointer(n->dev.rx_sock, NULL);
		fput(rx_sock->file);
	}
	synchronize_rcu_expedited();
	call_rcu(&n->dev.vq_chain_rcu, free_vq_chain_rcu);
	call_rcu(&n->dev.rcu, free_netdev_rcu);
	kfree(n->dev.vqs);
	kfree(n);
	return 0;
}