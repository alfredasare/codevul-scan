int compat_ipv6_setsockopt(struct sock *sk, int level, int optname,
                           char __user *optval, unsigned int optlen)
{
    ...
    if (err == -ENOPROTOOPT && optname != IPV6_IPSEC_POLICY &&
        optname != IPV6_XFRM_POLICY) {
        lock_sock(sk);
        err = compat_nf_setsockopt(sk, PF_INET6, optname,
                                   optval, optlen);
        unlock_sock(sk); // Ensure lock is released only after use
        return err;
    }
    ...
}