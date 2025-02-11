#include <pthread.h>

static pthread_mutex_t hpet_mutex = PTHREAD_MUTEX_INITIALIZER;

static void hpet_pre_save(void *opaque)
{
    HPETState *s = opaque;

    pthread_mutex_lock(&hpet_mutex);
    s->hpet_counter = hpet_get_ticks(s);
    pthread_mutex_unlock(&hpet_mutex);
}