static void tcp_mtup_probe_success(struct sock *sk)
{
    //...

    tp->snd_cwnd = (tp->snd_cwnd * tcp_mss_to_mtu(sk, tp->mss_cache)) / icsk->icsk_mtup.probe_size;
    tp->snd_cwnd = (tp->snd_cwnd > INT_MAX)? INT_MAX : tp->snd_cwnd;

    //...
}