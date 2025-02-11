#define BUFFER_SIZE 64 * sizeof(int16_t) // Adjusted for the correct size calculation

static void ff_jref_idct2_put(uint8_t *dest, int line_size, int16_t *block)
{
    // Add input validation
    if (block == NULL || sizeof(block) < BUFFER_SIZE) {
        // Handle error or insufficient buffer size
        return;
    }

    ff_j_rev_dct2(block);
    put_pixels_clamped2_c(block, dest, line_size);
}