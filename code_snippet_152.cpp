static void mp_shutdown(struct sb_uart_state *state)
{
	if (!state) {
		pr\_err("mp\_shutdown: Invalid state pointer\n");
		return;
	}

	struct sb\_uart\_info *info = state->info;
	struct sb\_uart\_port *port = state->port;

	if (!info) {
		pr\_err("mp\_shutdown: Invalid info pointer\n");
		return;
	}

	if (!port) {
		pr\_err("mp\_shutdown: Invalid port pointer\n");
		return;
	}

	if (info->tty)
		set\_bit(TTY\_IO\_ERROR, &info->tty->flags);

	if (info->flags & UIF\_INITIALIZED) {
		info->flags &= ~UIF\_INITIALIZED;

		if (!info->tty || (info->tty->termios.c\_cflag & HUPCL))
			uart\_clear\_mctrl(port, TIOCM\_DTR | TIOCM\_RTS);

		wake\_up\_interruptible(&info->delta\_msr\_wait);

		port->ops->shutdown(port);

		synchronize\_irq(port->irq);
	}
	tasklet\_kill(&info->tlet);

	if (info->xmit.buf) {
		free\_page((unsigned long)info->xmit.buf);
		info->xmit.buf = NULL;
	}
}