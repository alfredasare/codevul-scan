#define MAX_HEADER_SIZE sizeof(spf->header) / sizeof(spf->header[0])

header_put_be_8byte(SF_PRIVATE *psf, sf_count_t x)
{
    if (psf->headindex + 8 > MAX_HEADER_SIZE) {
        return;
    }
    psf->header[psf->headindex++] = 0;
    psf->header[psf->headindex++] = 0;
    psf->header[psf->headindex++] = 0;
    psf->header[psf->headindex++] = 0;
    psf->header[psf->headindex++] = (x >> 24);
    psf->header[psf->headindex++] = (x >> 16);
    psf->header[psf->headindex++] = (x >> 8);
    psf->header[psf->headindex++] = x;
}