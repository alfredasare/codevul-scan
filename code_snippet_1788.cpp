static long llc_ui_wait_for_conn(struct sock *sk, long timeout)
{
	DEFINE_WAIT(wait);
	long timeleft = timeout;

	while (1) {