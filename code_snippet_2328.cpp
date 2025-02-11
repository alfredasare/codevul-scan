static int do_siocgstampns(struct net *net, struct socket *sock,
                           unsigned int cmd, void __user *up)
{
        mm_segment_t old_fs = get_fs();
        struct timespec kts;
        int err;
        struct timespec user_kts; /* Copy of kts to return to user space */

        set_fs(KERNEL_DS);
        err = sock_do_ioctl(net, sock, cmd, (unsigned long)&kts);
        set_fs(old_fs);
        if (!err) {
                memcpy(&user_kts, &kts, sizeof(struct timespec));
                err = copy_to_user(up, &user_kts, sizeof(struct timespec));
                if (err)
                        return err;
        }

        return err;
}