static struct tty_ldisc *tty_ldisc_get(struct tty_struct *tty, int disc)
{
    struct tty_ldisc *ld;
    struct tty_ldisc_ops *ldops;

    if (disc < N_TTY || disc >= NR_LDISCS)
        return ERR_PTR(-EINVAL);

    ldops = get_ldops(disc);
    if (IS_ERR(ldops)) {
        request_module("tty-ldisc-%d", disc);
        ldops = get_ldops(disc);
        if (IS_ERR(ldops)) {
            kfree(ld);
            put_ldops(NULL);
            return ERR_CAST(ldops);
        }
    }

    ld = kmalloc(sizeof(struct tty_ldisc), GFP_KERNEL);
    if (ld == NULL) {
        put_ldops(ldops);
        return ERR_PTR(-ENOMEM);
    }

    if (!ldops) {
        kfree(ld);
        return ERR_PTR(-ENODEV);
    }

    ld->ops = ldops;
    ld->tty = tty;

    return ld;
}