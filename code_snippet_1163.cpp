static int sctp_setsockopt_autoclose(struct sock *sk, char __user *optval, unsigned int optlen)
{
    struct sctp_sock *sp = sctp_sk(sk);
    struct net *net = sock_net(sk);

    /* Applicable to UDP-style socket only */
    if (sctp_style(sk, TCP))
        return -EOPNOTSUPP;
    if (optlen!= sizeof(int))
        return -EINVAL;

    // Validate optval pointer
    if (!access_ok(VERIFY_READ, optval, optlen))
        return -EFAULT;

    // Copy data from user-space to kernel-space
    if (copy_from_user(&sp->autoclose, optval, optlen))
        return -EFAULT;

    if (sp->autoclose > net->sctp.max_autoclose)
        sp->autoclose = net->sctp.max_autoclose;

    return 0;
}