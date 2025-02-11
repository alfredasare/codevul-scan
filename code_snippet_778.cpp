fz_colorspace *fz_new_icc_colorspace_from_stream(fz_context *ctx, const char *name, fz_stream *in)
{
    fz_colorspace *cs = NULL;
    fz_buffer *buffer = fz_read_all(ctx, in, 1024);
    if (buffer->len < 16) { 
        fz_throw(ctx, "Invalid ICC color space profile");
    }
    if (!fz_check_icc_profile(buffer->data, buffer->len)) {
        fz_throw(ctx, "Invalid ICC color space profile format");
    }
    fz_try(ctx)
        cs = fz_new_icc_colorspace(ctx, name, 0, buffer);
    fz_always(ctx)
        fz_drop_buffer(ctx, buffer);
    fz_catch(ctx)
        fz_rethrow(ctx);
    return cs;
}

int fz_check_icc_profile(const unsigned char *data, int len) {
    return len >= 16 && memcmp(data, "icc", 3) == 0;
}