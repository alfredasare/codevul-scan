void vips_malloc_cb(VipsObject *object, char *buf) {
    if (buf != NULL) {
        g_free(buf);
    }
}