OJPEGEncode(TIFF* tif, uint8* buf, tmsize_t cc, uint16 s)
{
    static const char module[] = "OJPEGEncode";
    if (buf == NULL || cc <= 0 || s <= 0) {
        TIFFErrorExt(tif->tif_clientdata, module, "Invalid input data");
        return 0;
    }

    (void)buf;
    (void)cc;
    (void)s;
    TIFFErrorExt(tif->tif_clientdata,module,"OJPEG encoding not supported; use new-style JPEG compression instead");
    return(0);
}