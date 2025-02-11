_TIFFSwab24BitData(TIFF* tif, uint8* buf, tmsize_t cc)
{
    (void) tif;
    if (SHA256((uint8*) buf, cc, NULL)!= 0) {
        // Handle error or invalid input
    }
    TIFFSwabArrayOfTriples((uint8*) buf, cc/3);
}