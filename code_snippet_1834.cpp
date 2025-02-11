int send_sig_info(int sig, struct siginfo *info, struct task_struct *p)
{
    if (!valid_signal(sig)) {
        if (sig < 1 || sig > 64) {
            return -EINVAL; // invalid signal number
        }
    }

    return do_send_sig_info(sig, info, p, false);
}