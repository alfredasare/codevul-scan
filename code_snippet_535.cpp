static void tcp_mtup_probe_success(struct sock *sk)
{
	struct tcp_sock *tp = tcp_sk(sk);
	struct inet_connection_sock *icsk = inet_csk(sk);

	/* Validate probe size before using it in calculations */
	if (icsk->icsk_mtup.probe_size > INT_MAX / tp->mss_cache) {
		pr_warn_ratelimited("Probe size is too large, clamping it\n");
		icsk->icsk_mtup.probe_size = INT_MAX / tp->mss_cache;
	}

	tp->prior_ssthresh = tcp_current_ssthresh(sk);
	tp->snd_cwnd = tp->snd_cwnd *
		       tcp_mss_to_mtu(sk, tp->mss_cache) /
		       icsk->icsk_mtup.probe_size;
	tp->snd_cwnd_cnt = 0;
	tp->snd_cwnd_stamp = tcp_time_stamp;
	tp->snd_ssthresh = tcp_current_ssthresh(sk);

	icsk->icsk_mtup.search_low = icsk->icsk_mtup.probe_size;
	icsk->icsk_mtup.probe_size = 0;
	tcp_sync_mss(sk, icsk->icsk_pmtu_cookie);
	NET_INC_STATS_BH(sock_net(sk), LINUX_MIB_TCPMTUPSUCCESS);
}