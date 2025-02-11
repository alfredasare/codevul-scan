BGD\_DECLARE(void *) gdImageWebpPtr (gdImagePtr im, int *size)
{
	void *rv;
	gdIOCtx *out = gdNewDynamicCtx(2048, NULL);
	if (out == NULL) {
		return NULL;
	}
	if (gdImageWebpCtx(im, out, -1) != 0) { // Add error checking for gdImageWebpCtx
		out->gd_free(out);
		return NULL;
	}
	rv = gdDPExtractData(out, size);
	out->gd_free(out);

	return rv;
}