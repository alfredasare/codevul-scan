SYSCALL_DEFINE3(sendmsg, int, fd, struct msghdr __user *, msg, unsigned int, flags)
{
    int fput_needed, err;
    struct msghdr msg_sys;
    struct socket *sock = sockfd_lookup_light(fd, &err, &fput_needed);

    if (!sock)
        goto out;

    msg_sys.msg_name = NULL;
    msg_sys.msg_namelen = 0;
    msg_sys.msg_iov = NULL;
    msg_sys.msg_iovlen = 0;
    msg_sys.msg_control = NULL;
    msg_sys.msg_controllen = 0;
    msg_sys.msg_flags = flags;

    if (msg) {
        if (msg->msg_name) {
            if (msg->msg_namelen > MSG_MAXLEN) {
                err = -ENAMETOOLONG;
                goto out;
            }
        }
        if (msg->msg_control) {
            if (msg->msg_controllen > CTL_MAXLEN) {
                err = -ENAMETOOLONG;
                goto out;
            }
        }
    }

    err = __sys_sendmsg(sock, msg, &msg_sys, flags, NULL);

    fput_light(sock->file, fput_needed);
out:
    return err;
}