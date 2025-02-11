BGD\_DECLARE(gdImagePtr) gdImageCreateFromWebp (FILE * inFile)
{
	gdImagePtr im;
	gdIOCtx *in = gdNewFileCtx(inFile);
	if (!in) {
		return 0;
	}
	if (in->io\_seek(in, 0, SEEK\_SET, NULL) != 0) { // Modified line
		in->gd\_free(in);
		return 0;
	}
	im = gdImageCreateFromWebpCtx(in);
	in->gd\_free(in);

	return im;
}