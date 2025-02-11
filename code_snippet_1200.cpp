#include <pthread.h>

static pthread_mutex_t current_time_mutex = PTHREAD_MUTEX_INITIALIZER;

static void set_current_time(void) {
    struct timeval timer;
    pthread_mutex_lock(&current_time_mutex);
    gettimeofday(&timer, NULL);
    current_time = (rel_time_t) (timer.tv_sec - process_started);
    pthread_mutex_unlock(&current_time_mutex);
}