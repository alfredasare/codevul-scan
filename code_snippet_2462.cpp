static int tcp_repair_options_est(struct tcp_sock *tp,
                                 struct tcp_repair_opt __user *optbuf,
                                 unsigned int len)
{
    struct tcp_repair_opt opt;

    if (len < sizeof(opt)) {
        return -EINVAL; // Invalid length
    }

    if (copy_from_user(&opt, optbuf, sizeof(opt))) {
        return -EFAULT; // Failed to copy from user space
    }

    optbuf++;
    len -= sizeof(opt);

    if (len < 0) {
        return -EINVAL; // Insufficient buffer size
    }

    switch (opt.opt_code) {
    case TCPOPT_MSS:
        if (opt.opt_val > TCP_MSS_MAX) {
            return -EINVAL; // MSS value out of range
        }
        tp->rx_opt.mss_clamp = opt.opt_val;
        break;
    case TCPOPT_WINDOW:
        {
            u16 snd_wscale = opt.opt_val & 0xFFFF;
            u16 rcv_wscale = opt.opt_val >> 16;

            if (snd_wscale > 14 || rcv_wscale > 14) {
                return -EFBIG; // Wscale value out of range
            }

            tp->rx_opt.snd_wscale = snd_wscale;
            tp->rx_opt.rcv_wscale = rcv_wscale;
            tp->rx_opt.wscale_ok = 1;
        }
        break;
    case TCPOPT_SACK_PERM:
        if (opt.opt_val != 0) {
            return -EINVAL; // Invalid SACK value
        }
        tp->rx_opt.sack_ok |= TCP_SACK_SEEN;
        if (sysctl_tcp_fack)
            tcp_enable_fack(tp);
        break;
    case TCPOPT_TIMESTAMP:
        if (opt.opt_val != 0) {
            return -EINVAL; // Invalid timestamp value
        }
        tp->rx_opt.tstamp_ok = 1;
        break;
    }

    return 0;
}