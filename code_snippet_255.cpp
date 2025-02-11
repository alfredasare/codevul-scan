int tipc_sock_accept_local(struct socket *sock, struct socket **newsock, int flags)
{
    struct sock *sk = sock->sk;
    int ret;

    if (!newsock ||!(*newsock)) {
        return -ENOMEM; // invalid newsock pointer
    }

    if (flags!= 0) { // only allow 0 as a valid flag value
        return -EINVAL; // invalid flags
    }

    ret = sock_create_lite(sk->sk_family, sk->sk_type, sk->sk_protocol, newsock);
    if (ret < 0)
        return ret;

    ret = accept(sock, *newsock, flags);
    if (ret < 0) {
        if (ret == -EINVAL) {
            // invalid flags, return an error
            return -EINVAL;
        } else if (ret == -ENOMEM) {
            // invalid newsock pointer, return an error
            sock_release(*newsock);
            return -ENOMEM;
        }
        // handle other error cases as needed
    }

    (*newsock)->ops = sock->ops;
    return ret;
}