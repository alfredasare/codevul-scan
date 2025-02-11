static int __sys_getsockopt(int fd, int level, int optname,
                            char __user *optval, int __user *optlen)
{
        int err, fput_needed, max_optlen;
        struct socket *sock;

        sock = sockfd_lookup_light(fd, &err, &fput_needed);
        if (sock != NULL) {
                err = security_socket_getsockopt(sock, level, optname);
                if (err)
                        goto out_put;

                if (level == SOL_SOCKET)
                        max_optlen = min(*optlen, SOCK_MAX_OPT);
                else
                        max_optlen = min(*optlen, sock->ops->getsockopt_size(sock, level, optname));

                if (*optlen < max_optlen) {
                        err = -EINVAL;
                        goto out_put;
                }

                *optlen = max_optlen;
                err = sock->ops->getsockopt(sock, level, optname, optval, optlen);
                if (err && *optlen < max_optlen) {
                        err = -EOVERFLOW;
                        goto out_put;
                }

                err = (*optlen > 0) ? 0 : -ENODATA;
out_put:
                fput_light(sock->file, fput_needed);
        }
        return err;
}