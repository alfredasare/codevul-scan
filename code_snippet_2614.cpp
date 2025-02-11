#include <linux/rwlock.h>

struct task_struct {
	/* other members */
	struct rw_semaphore sighand_rwsem;
};

void flush_signal_handlers(struct task_struct *t, int force_default)
{
	struct k_sigaction *ka, *ka_end;
	int i;

	read_lock(&t->sighand_rwsem);
	ka = &t->sighand->action[0];
	ka_end = &t->sighand->action[_NSIG];

	for (i = _NSIG ; i != 0 ; i--) {
		if (force_default || ka->sa.sa_handler != SIG_IGN)
			ka->sa.sa_handler = SIG_DFL;
		ka->sa.sa_flags = 0;
		sigemptyset(&ka->sa.sa_mask);

		if (ka++ == ka_end)
			break;
	}

	read_unlock(&t->sighand_rwsem);
}