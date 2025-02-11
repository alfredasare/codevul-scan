static inline void check_stack_usage(void) {
    char buffer[16]; // Limited stack buffer size
    if (snprintf(buffer, sizeof(buffer), "%s", some_input_string) >= sizeof(buffer)) {
        // Handle overflow error
    }
}