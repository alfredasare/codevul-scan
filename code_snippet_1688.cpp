#include <pthread.h>

pthread_mutex_t bench_display_mutex = PTHREAD_MUTEX_INITIALIZER;

void switch_bench(u32 is_on)
{
    pthread_mutex_lock(&bench_display_mutex);

    bench_mode = is_on;
    display_rti = is_on ? 2 : 0;
    ResetCaption();
    gf_term_set_option(term, GF_OPT_VIDEO_BENCH, is_on);

    pthread_mutex_unlock(&bench_display_mutex);
}