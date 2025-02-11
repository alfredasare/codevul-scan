static void llc_cmsg_rcv(struct msghdr *msg, struct sk_buff *skb)
{
	struct llc_sock *llc = llc_sk(skb->sk);
	struct llc_pktinfo info = { 0 };

	if (llc->cmsg_flags & LLC_CMSG_PKTINFO) {
		llc_pdu_decode_dsap(skb, &info.lpi_sap);
		llc_pdu_decode_da(skb, info.lpi_mac);
		info.lpi_ifindex = llc_sk(skb->sk)->dev->ifindex;

		if (capable(CAP_NET_ADMIN)) {
			put_cmsg(msg, SOL_LLC, LLC_OPT_PKTINFO, sizeof(info), &info);
		}
	}
}