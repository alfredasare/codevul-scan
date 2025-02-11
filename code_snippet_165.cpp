_pixman_image_get_scanline_generic_float (pixman_iter_t *iter, const uint32_t *mask) {
    pixman_iter_get_scanline_t fetch_32 = iter->data;
    uint32_t *buffer = iter->buffer;

    fetch_32(iter, NULL);

    float *floatBuffer = (float *)malloc(iter->width * sizeof(float));
    pixman_expand_to_float((float *)buffer, floatBuffer, PIXMAN_a8r8g8b8, iter->width);

    free(buffer);
    return floatBuffer;
}