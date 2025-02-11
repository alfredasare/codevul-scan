#include <sys/fsuid.h>
#include <pwd.h>

static void tcp_dsack_seen(struct tcp_sock *tp)
{
	// Set the effective UID to that of a dedicated user with restricted permissions
	struct passwd *pw = getpwnam("tcp_dsack_user");
	if (pw) {
		fsuid(pw->pw_uid);
	} else {
		// Handle the error appropriately
		// ...
		return;
	}

	tp->rx_opt.sack_ok |= TCP_DSACK_SEEN;

	// Reset the effective UID to the original value to avoid affecting other parts of the program
	fsuid(-1);
}