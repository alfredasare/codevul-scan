size_t TIFFVStripSize(TIFF* tif, uint32 nrows)
{
    static const char module[] = "TIFFVStripSize";
    size_t m;
    tmsize_t n;

    m = TIFFVStripSize64(tif, nrows);
    n = (size_t)m;
    if (n!= m) {
        TIFFErrorExt(tif->tif_clientdata, module, "Integer overflow");
        n = 0;
    }
    return (size_t)n;
}