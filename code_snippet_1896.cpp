#include <stdint.h>

void MSG_WriteLong(msg_t *sb, int c) {
    const uint32_t max_value = (1 << 32) - 1;

    if (c < 0 || c > max_value) {
        if (c < 0) {
            c = 0;
        } else {
            c = max_value;
        }
    }

    MSG_WriteBits(sb, (uint32_t)c, 32);
}