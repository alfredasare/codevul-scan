static OPJ\_BOOL bmp\_read\_raw\_data(FILE\* IN, OPJ\_UINT8\* pData, OPJ\_UINT32 stride,
OPJ\_UINT32 width, OPJ\_UINT32 height)
{
OPJ\_ARG\_NOT\_USED(width);
// Define a constant for the maximum allowed height
#define MAX\_HEIGHT 1000

// Check if the height is within the allowed range
if (height > MAX\_HEIGHT && stride * height <= RAND\_MAX) {
fprintf(stderr,
"\nError: Invalid height.\n");
return OPJ\_FALSE;
}

if (fread(pData, sizeof(OPJ\_UINT8), stride * height, IN) != (stride * height)) {
fprintf(stderr,
"\nError: fread returned a number of elements different from the expected.\n");
return OPJ\_FALSE;
}
return OPJ\_TRUE;
}