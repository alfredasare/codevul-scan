static inline bool forced_push(const struct tcp_sock *tp)
{
    int shifted_seq = (tp->pushed_seq + (tp->max_window >> 1)) & ((1 << 31) - 1);
    return after(tp->write_seq, shifted_seq);
}