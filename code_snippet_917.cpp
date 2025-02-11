static int qcow2_change_backing_file(BlockDriverState *bs,
                                     const char *backing_file, const char *backing_fmt)
{
    if (backing_file) {
        snprintf(bs->backing_file, sizeof(bs->backing_file), "%s", backing_file);
    } else {
        bs->backing_file[0] = '\0';
    }

    if (backing_fmt) {
        snprintf(bs->backing_format, sizeof(bs->backing_format), "%s", backing_fmt);
    } else {
        bs->backing_format[0] = '\0';
    }

    return qcow2_update_header(bs);
}