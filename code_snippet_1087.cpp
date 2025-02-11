BGD_DECLARE(void *) gdImageGd2Ptr (gdImagePtr im, int cs, int fmt, int *size)
{
    void *rv;
    gdIOCtx *out = gdNewDynamicCtx (2048, NULL);
    if (out == NULL) return NULL;

    if (*size > out->buffer_size) {
        error("Invalid size value");
        return NULL;
    }

    _gdImageGd2 (im, out, cs, fmt);
    rv = gdDPExtractData (out, *size);
    out->gd_free (out);
    return rv;
}