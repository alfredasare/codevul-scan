static int tiff_closeproc(thandle_t clientdata)
{
	(void)clientdata;
	tiff_handle *th = (tiff_handle *)clientdata;
	gdIOCtx *ctx = th->ctx;

        if (ctx && ctx-> ged_magic == GD_IO_MAGIC) {
                (ctx->gd_free)(ctx);
                th->ctx = NULL;
        }

	return 0;
}