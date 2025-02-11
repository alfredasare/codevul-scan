static void tcp_illinois_init(struct sock *sk)
{
    struct illinois *ca = inet_csk_ca(sk);

    ca->alpha = ALPHA_MAX;
    ca->beta = BETA_BASE;
    ca->base_rtt = (uint32_t)0x7fffffff;
    ca->max_rtt = (uint32_t)0;

    ca->acked = 0;
    ca->rtt_low = 0;
    ca->rtt_above = 0;

    rtt_reset(sk);
}