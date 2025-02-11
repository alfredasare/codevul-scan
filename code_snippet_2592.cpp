BGD\_DECLARE(int) gdTransformAffineGetImage(gdImagePtr *restrict dst,
const gdImagePtr src,
gdRectPtr src\_area,
const double affine[6])
{
if (dst == NULL || *dst != NULL) {
return GD\_FALSE;
}

...

return GD\_TRUE;
}