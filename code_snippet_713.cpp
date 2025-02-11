static inline void notify_cmos_timer(int timer_value) {
    if (timer_value < 0 || timer_value > INT_MAX) {
        fprintf(stderr, "Invalid timer value received: %d\n", timer_value);
        return;
    }

    // Add the actual functionality here
}