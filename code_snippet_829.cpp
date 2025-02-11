static int iwgif_read_file_header(struct iwgifrcontext *rctx)
{
	int read_bytes = iwigif_read(rctx, rctx->rbuf, 6);
	if (read_bytes != 6) {
		fprintf(stderr, "Unexpected number of bytes read from input: %d\n", read_bytes);
		return 0;
	}

	if (rctx->rbuf[0] != 'G' || rctx->rbuf[1] != 'I' || rctx->rbuf[2] != 'F') {
		iw_set_error(rctx->ctx,"Not a GIF file");
		return 0;
	}

	return 1;
}