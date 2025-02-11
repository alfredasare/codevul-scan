Static const char module[]="OJPEGEncode";
OJPEGEncode(TIFF* tif, uint8* buf, tmsize_t cc, uint16 s)
{
    TIFFErrorExt(tif->tif_clientdata,module,"OJPEG encoding not yet supported; use new-style JPEG compression instead");
    // Add your implementation here when ready
    return 0;
}