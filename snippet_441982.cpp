static void handle_tx_copy(struct vhost_net *net, struct socket *sock)
{
	struct vhost_net_virtqueue *nvq = &net->vqs[VHOST_NET_VQ_TX];
	struct vhost_virtqueue *vq = &nvq->vq;
	unsigned out, in;
	int head;
	struct msghdr msg = {
		.msg_name = NULL,
		.msg_namelen = 0,
		.msg_control = NULL,
		.msg_controllen = 0,
		.msg_flags = MSG_DONTWAIT,
	};
	size_t len, total_len = 0;
	int err;
	int sent_pkts = 0;
	bool sock_can_batch = (sock->sk->sk_sndbuf == INT_MAX);

	do {
		bool busyloop_intr = false;

		if (nvq->done_idx == VHOST_NET_BATCH)
			vhost_tx_batch(net, nvq, sock, &msg);

		head = get_tx_bufs(net, nvq, &msg, &out, &in, &len,
				   &busyloop_intr);
		/* On error, stop handling until the next kick. */
		if (unlikely(head < 0))
			break;
		/* Nothing new?  Wait for eventfd to tell us they refilled. */
		if (head == vq->num) {
			if (unlikely(busyloop_intr)) {
				vhost_poll_queue(&vq->poll);
			} else if (unlikely(vhost_enable_notify(&net->dev,
								vq))) {
				vhost_disable_notify(&net->dev, vq);
				continue;
			}
			break;
		}

		total_len += len;

		/* For simplicity, TX batching is only enabled if
		 * sndbuf is unlimited.
		 */
		if (sock_can_batch) {
			err = vhost_net_build_xdp(nvq, &msg.msg_iter);
			if (!err) {
				goto done;
			} else if (unlikely(err != -ENOSPC)) {
				vhost_tx_batch(net, nvq, sock, &msg);
				vhost_discard_vq_desc(vq, 1);
				vhost_net_enable_vq(net, vq);
				break;
			}

			/* We can't build XDP buff, go for single
			 * packet path but let's flush batched
			 * packets.
			 */
			vhost_tx_batch(net, nvq, sock, &msg);
			msg.msg_control = NULL;
		} else {
			if (tx_can_batch(vq, total_len))
				msg.msg_flags |= MSG_MORE;
			else
				msg.msg_flags &= ~MSG_MORE;
		}

		/* TODO: Check specific error and bomb out unless ENOBUFS? */
		err = sock->ops->sendmsg(sock, &msg, len);
		if (unlikely(err < 0)) {
			vhost_discard_vq_desc(vq, 1);
			vhost_net_enable_vq(net, vq);
			break;
		}
		if (err != len)
			pr_debug("Truncated TX packet: len %d != %zd\n",
				 err, len);
done:
		vq->heads[nvq->done_idx].id = cpu_to_vhost32(vq, head);
		vq->heads[nvq->done_idx].len = 0;
		++nvq->done_idx;
	} while (likely(!vhost_exceeds_weight(vq, ++sent_pkts, total_len)));

	vhost_tx_batch(net, nvq, sock, &msg);
}