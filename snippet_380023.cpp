 * Malformed skbs with wrong lengths or invalid creds are not processed.
 */
static void
iscsi_if_rx(struct sk_buff *skb)
{
	u32 portid = NETLINK_CB(skb).portid;

	mutex_lock(&rx_queue_mutex);
	while (skb->len >= NLMSG_HDRLEN) {
		int err;
		uint32_t rlen;
		struct nlmsghdr	*nlh;
		struct iscsi_uevent *ev;
		uint32_t group;
		int retries = ISCSI_SEND_MAX_ALLOWED;

		nlh = nlmsg_hdr(skb);
		if (nlh->nlmsg_len < sizeof(*nlh) + sizeof(*ev) ||
		    skb->len < nlh->nlmsg_len) {
			break;
		}

		ev = nlmsg_data(nlh);
		rlen = NLMSG_ALIGN(nlh->nlmsg_len);
		if (rlen > skb->len)
			rlen = skb->len;

		err = iscsi_if_recv_msg(skb, nlh, &group);
		if (err) {
			ev->type = ISCSI_KEVENT_IF_ERROR;
			ev->iferror = err;
		}
		do {
			/*
			 * special case for GET_STATS:
			 * on success - sending reply and stats from
			 * inside of if_recv_msg(),
			 * on error - fall through.
			 */
			if (ev->type == ISCSI_UEVENT_GET_STATS && !err)
				break;
			if (ev->type == ISCSI_UEVENT_GET_CHAP && !err)
				break;
			err = iscsi_if_send_reply(portid, nlh->nlmsg_type,
						  ev, sizeof(*ev));
			if (err == -EAGAIN && --retries < 0) {
				printk(KERN_WARNING "Send reply failed, error %d\n", err);
				break;
			}
		} while (err < 0 && err != -ECONNREFUSED && err != -ESRCH);
		skb_pull(skb, rlen);