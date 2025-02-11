static int iwgif_read_file_header(struct iwgifrcontext *rctx)
{
    if (!iwgif_read(rctx, rctx->rbuf, 6)) {
        if (rctx->rbuf) free(rctx->rbuf); // Ensure memory is released on error
        return 0;
    }
    if (rctx->rbuf[0]!= 'G' || rctx->rbuf[1]!= 'I' || rctx->rbuf[2]!= 'F') {
        iw_set_error(rctx->ctx, "Not a GIF file");
        if (rctx->rbuf) free(rctx->rbuf); // Ensure memory is released on error
        return 0;
    }
    return 1;
}