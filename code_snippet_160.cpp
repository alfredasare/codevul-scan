#define BUFFER_SIZE 64

static inline void check_stack_usage(void) {
    char buffer[BUFFER_SIZE];
    secure_strncpy(buffer, "Safe string", BUFFER_SIZE);
}

void secure_strncpy(char *dest, const char *src, size_t n) {
    // Use strnlen() to determine the length of src
    size_t src_len = strnlen(src, n);

    // Copy up to n characters from src to dest, followed by a null terminator
    memcpy(dest, src, src_len);
    dest[src_len] = '\0';

    // Ensure that dest does not get overfilled if src_len == n
    if (src_len < n) {
        memset(dest + src_len, 0, n - src_len);
    }
}