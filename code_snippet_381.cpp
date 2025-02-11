static int tiocgsid(struct tty_struct *tty, struct tty_struct *real_tty, pid_t __user *p)
{
	struct session *session;

	if (tty == real_tty && current->signal->tty != real_tty)
		return -ENOTTY;

	session = real_tty->session;
	if (!session)
		return -ENOTTY;

	return put_user(pid_vnr(session), p);
}