gdImagePtr gdImageCreateFromWBMP\_safe(FILE *inFile)
{
	gdImagePtr im;
	gdIOCtx *in = gdNewFileCtxAuto(inFile);
	im = gdImageCreateFromWBMPCtx(in);
	in->gd_free(in);

	return im;
}