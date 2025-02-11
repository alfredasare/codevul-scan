static inline void tcp_push(struct sock *sk, int flags, int mss_now,
                            int nonagle, int len)
{
        if (tcp_send_head(sk)) {
                struct tcp_sock *tp = tcp_sk(sk);

                if (len > tcp_send_head(sk)->end - tcp_send_head(sk)->data) {
                        printk(KERN_WARNING "Data length exceeds buffer size\n");
                        return;
                }

                if (!(flags & MSG_MORE) || forced_push(tp))
                        tcp_mark_push(tp, tcp_write_queue_tail(sk));

                tcp_mark_urg(tp, flags);
                __tcp_push_pending_frames(sk, mss_now,
                                          (flags & MSG_MORE) ? TCP_NAGLE_CORK : nonagle);
        }
}