_TIFFSwab24BitData(TIFF* tif, uint8* buf, tmsize_t cc)
{
    (void) tif;
    assert(cc >= 0);

    if (cc % 3 != 0) {
        return;
    }

    TIFFSwabArrayOfTriples((uint8*) buf, cc/3);
}