static int tiocgsid(struct tty_struct *tty, struct tty_struct *real_tty, pid_t __user *p)
{
    spinlock_t *lock = &real_tty->session_lock;
    spin_lock_irqsave(lock, flags);

    if (tty == real_tty && current->signal->tty!= real_tty)
        return -ENOTTY;
    if (!real_tty->session)
        return -ENOTTY;

    put_user(pid_vnr(real_tty->session), p);

    spin_unlock_irqrestore(lock, flags);
    return 0;
}