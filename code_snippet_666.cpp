#include <string.h>

static void vnc_write_pixels_copy(VncState *vs, void *pixels, int size)
{
    const size_t buffer_size = vs->buffer_size; // Ensure you have a buffer size defined in your VncState structure
    if (size < buffer_size) {
        memcpy_s(vs->output_buffer, buffer_size, pixels, size);
        vnc_write(vs, vs->output_buffer, size);
    } else {
        // Handle error scenario, size should not exceed buffer_size
    }
}