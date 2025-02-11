void header_put_be_8byte(SF\_PRIVATE \*psf, sf\_count\_t x)
{
    if (psf->headindex < SIGNED\_SIZEOF(psf->header) - 8)
    {
        psf->header[psf->headindex++] = (uint8\_t)((x >> 24) & 0xFF);
        psf->header[psf->headindex++] = (uint8\_t)((x >> 16) & 0xFF);
        psf->header[psf->headindex++] = (uint8\_t)((x >> 8) & 0xFF);
        psf->header[psf->headindex++] = (uint8\_t)(x & 0xFF);
    }
    else
    {
        // Handle error case, buffer overflows can lead to security vulnerabilities
        // Implement appropriate error handling or return statement here
    }
}