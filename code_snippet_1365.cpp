static void set_current_time(void) {
    struct timeval timer;

    if (gettimeofday(&timer, NULL) != 0) {
        // Handle error
    }

    if (timer.tv_sec < 0 || timer.tv_usec < 0 || timer.tv_usec >= 1000000) {
        // Handle invalid input
    } else {
        current_time = (rel_time_t) (timer.tv_sec - process_started);
    }
}