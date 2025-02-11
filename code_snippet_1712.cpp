static int hidp_sock_release(struct socket *sock)
{
    struct sock *sk = sock->sk;

    BT_DBG("sock %p sk %p", sock, sk);

    if (!sk ||!is_allowed_sk_value(sk)) {
        return -EINVAL;
    }

    bt_sock_unlink(&hidp_sk_list, sk);

    sock_orphan(sk);
    sock_put(sk);

    return 0;
}

int is_allowed_sk_value(struct sock *sk)
{
    return (sk >= &hidp_sk_min && sk <= &hidp_sk_max);
}