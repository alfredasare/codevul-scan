static void tcp_dsack_seen(struct tcp_sock *tp)
{
    if (tp->rx_opt.sack_ok) {
        // Handle the case when sack_ok is already set
        //...
    } else {
        // Set sack_ok only when it's not already set
        tp->rx_opt.sack_ok = TCP_DSACK_SEEN;
    }
}