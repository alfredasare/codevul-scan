static int sctp_error(struct sock *sk, int flags, int err)
{
    if (err < 0 && err!= -ECONNREFUSED && err!= -ENOTCONN) {
        err = sock_error(sk)? : -EPIPE;
    }
    if (err == -EPIPE &&!(flags & MSG_NOSIGNAL)) {
        send_sig(SIGPIPE, current, 0);
    }
    return err;
}