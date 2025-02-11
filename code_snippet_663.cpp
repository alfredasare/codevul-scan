BGD_DECLARE(gdImagePtr) gdImageCreateFromWebp (FILE * inFile)
{
    gdImagePtr im;
    gdIOCtx *in = gdNewFileCtx(inFile);
    if (!in) {
        return 0;
    }
    uint32_t fileSize = (uint32_t)fseeko(inFile, 0, SEEK_END);
    if (fileSize > GD_MAX_IMAGE_SIZE) {
        return 0;
    }
    im = gdImageCreateFromWebpCtx(in);
    in->gd_free(in);
    return im;
}