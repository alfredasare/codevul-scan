static inline void tcp_push(struct sock *sk, int flags, int mss_now, int nonagle)
{
    if (tcp_send_head(sk)) {
        struct tcp_sock *tp = tcp_sk(sk);

        if (!(flags & MSG_MORE) || forced_push(tp))
            tcp_mark_push(tp, tcp_write_queue_tail(sk));

        if (flags & MSG_OOB)
            tcp_mark_urg(tp, flags);

        __tcp_push_pending_frames(sk, mss_now, (flags & MSG_MORE) ? TCP_NAGLE_CORK : nonagle);
    }
}

void tcp_mark_urg(struct tcp_sock *tp, int flags)
{
    if (flags & MSG_OOB) {
        u16 *urg_data = (u16 *)tcp_urg_ptr(tp);
        int size = sizeof(u16);

        if (size > tp->urg_size) {
            kfree(tcp_urg_ptr(tp));
            tp->urg_size = size;
            tcp_urg_ptr(tp) = kmalloc(size, GFP_KERNEL);
        }

        memcpy(tcp_urg_ptr(tp), &urg_data, size);
    }
}