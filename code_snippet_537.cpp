#include <pthread.h>

pthread_mutex_t g_runner_handlers_mutex = PTHREAD_MUTEX_INITIALIZER;

int tcmur_register_handler(struct tcmur_handler *handler)
{
	struct tcmur_handler *h;
	int i;

	pthread_mutex_lock(&g_runner_handlers_mutex);

	for (i = 0; i < darray_size(g_runner_handlers); i++) {
		h = darray_item(g_runner_handlers, i);
		if (!strcmp(h->subtype, handler->subtype)) {
			tcmu_err("Handler %s has already been registered\n",
				 handler->subtype);
			pthread_mutex_unlock(&g_runner_handlers_mutex);
			return -1;
		}
	}

	darray_append(g_runner_handlers, handler);
	pthread_mutex_unlock(&g_runner_handlers_mutex);
	return 0;
}