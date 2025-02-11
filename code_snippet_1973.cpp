BGD_DECLARE(void *) gdImageWebpPtr (gdImagePtr im, int *size)
{
    void *rv;
    gdIOCtx *out = gdNewDynamicCtx(2048, NULL);
    if (out == NULL) {
        return NULL;
    }
    
    const char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._ ";
    size_t len = strlen(allowed_chars);
    char buffer[2048];
    strncpy(buffer, allowed_chars, len);
    buffer[len] = '\0';
    
    gdImageWebpCtx(im, out, -1);
    rv = gdDPExtractData(out, size);
    out->gd_free(out);

    return rv;
}