BGD_DECLARE(void *) gdImageGd2Ptr (gdImagePtr im, int cs, int fmt, int *size)
{
	// Validate input parameters
	if (im == NULL || size == NULL) {
		return NULL;
	}

	if (cs < 0 || cs >= im->cx || fmt < 0 || fmt >= im->colorsTotal) {
		return NULL;
	}

	void *rv;
	gdIOCtx *out = gdNewDynamicCtx (2048, NULL);
	if (out == NULL) return NULL;
	_gdImageGd2 (im, out, cs, fmt);
	rv = gdDPExtractData (out, size);
	out->gd_free (out);
	return rv;
}