static void import_format(CDXLVideoContext *c, int linesize, uint8_t **out)
{
    // Validate linesize
    if (linesize <= 0 || linesize > 1024) { 
        return; 
    }

    // Allocate a secure buffer
    *out = malloc(linesize * c->avctx->height);
    if (!*out) {
        return; 
    }

    memset(*out, 0, linesize * c->avctx->height);

    //... rest of the function...

    free(*out); 
}