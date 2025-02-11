n_tty_receive_signal_char(struct tty_struct *tty, int signal, unsigned char c)
{
	isig(signal, tty);
	if (I_IXON(tty))