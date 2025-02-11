char *enl_send_and_wait(char *msg)
{
	char *reply = IPC_TIMEOUT;
	sighandler_t old_alrm;
	Window current_ipc_win = ipc_win;

	if (e17_fake_ipc)
		return IPC_FAKE;

	if (current_ipc_win == None) {
		for (; current_ipc_win == None && enl_ipc_get_win() != None;) {
			current_ipc_win = enl_ipc_get_win();
		}
	}

	old_alrm = (sighandler_t) signal(SIGALRM, (sighandler_t) enl_ipc_timeout);
	for (; reply == IPC_TIMEOUT;) {
		timeout = 0;
		enl_ipc_send(msg, current_ipc_win);
		for (; !(reply = enl_ipc_get(enl_wait_for_reply(), current_ipc_win)););
		if (reply == IPC_TIMEOUT) {
			D(("IPC timed out.  IPC window has gone. Clearing ipc_win.\n"));
			XSelectInput(disp, current_ipc_win, None);
			current_ipc_win = None;
		}
	}
	signal(SIGALRM, old_alrm);
	ipc_win = current_ipc_win; // Update the global value after the atomic operation
	return(reply);
}