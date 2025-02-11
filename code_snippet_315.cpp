gdImagePtr gdImageCreateFromWBMP(FILE *inFile) {
    gdImagePtr im;
    gdIOCtx *in = gdNewFileCtx(inFile);
    im = gdImageCreateFromWBMPCtx(in);
    gd_free(in);
    return im;
}