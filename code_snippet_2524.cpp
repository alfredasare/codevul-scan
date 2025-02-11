#include <stdarg.h>
#include <stddef.h>
#include <string.h>

// Function to check if a string contains only allowed characters
int is_safe_string(const char *str, const char *allowed_chars) {
    while (*str) {
        const char *c = strchr(allowed_chars, *str);
        if (!c) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Updated pdu_unmarshal function with input validation
ssize_t pdu_unmarshal(V9fsPDU *pdu, size_t offset, const char *fmt, ...) {
    ssize_t ret;
    va_list ap;

    // Validate fmt
    const char safe_chars[] = "%-0+ #*dif"; // Allow only these format specifiers
    if (!is_safe_string(fmt, safe_chars)) {
        // Handle error: invalid format string
        return -1;
    }

    va_start(ap, fmt);
    ret = virtio_pdu_vunmarshal(pdu, offset, fmt, ap);
    va_end(ap);

    return ret;
}