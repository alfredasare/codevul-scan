static void tcp_rearm_rto(struct sock *sk)
{
	const struct tcp_sock *tp = tcp_sk(sk);
	unsigned int packets_out = tp->packets_out;

	if (packets_out == 0) {
		inet_csk_clear_xmit_timer(sk, ICSK_TIME_RETRANS);
	} else {
		inet_csk_reset_xmit_timer(sk, ICSK_TIME_RETRANS,
					  inet_csk(sk)->icsk_rto, TCP_RTO_MAX);
	}
}