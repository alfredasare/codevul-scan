static int sctp_error(struct sock *sk, int flags, int err)
{
	if (err == -EPIPE)
		err = sk_stream_error(sk) ? : GENERIC_CONNECTION_RESET;
	if (err == GENERIC_CONNECTION_RESET && !(flags & MSG_NOSIGNAL))
		send_sig(SIGPIPE, current, 0);
	return err;
}