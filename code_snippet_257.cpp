int tipc_sock_accept_local(struct socket *sock, struct socket **newsock,
                           int flags)
{
        struct sock *sk = sock->sk;
        int ret;

        if (sk->sk_family != AF_INET && sk->sk_family != AF_INET6)
                return -EINVAL;

        if (sk->sk_type != SOCK_STREAM && sk->sk_type != SOCK_DGRAM)
                return -EINVAL;

        if (sk->sk_protocol != IPPROTO_TCP && sk->sk_protocol != IPPROTO_UDP)
                return -EINVAL;

        ret = sock_create_lite(sk->sk_family, sk->sk_type,
                               sk->sk_protocol, newsock);
        if (ret < 0)
                return ret;

        ret = accept(sock, *newsock, flags);
        if (ret < 0) {
                sock_release(*newsock);
                return ret;
        }
        (*newsock)->ops = sock->ops;
        return ret;
}