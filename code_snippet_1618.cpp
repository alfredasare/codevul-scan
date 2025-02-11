#include <stdint.h>

static void interface_set_compression_level(QXLInstance *sin, int level)
{
    dprint(1, "%s/%d:\n", __func__, sin->id);

    // Validate the input 'level'
    if (level < 0 || level > 100) {
        // Handle invalid input, e.g., return an error code or log an error message
        return;
    }

    // Sanitize the input 'level'
    uint8_t sanitized_level = (uint8_t)level;

    // Set the compression level
    sin->compression_level = sanitized_level;
}