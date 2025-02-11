void gdImageColorTransparent (gdImagePtr im, int color)
{
    if (color < 0 || color >= im->colorsTotal) {
        return;
    }
    if (!im->trueColor) {
        /* Make the old transparent color opaque again */
        if (im->transparent != -1) {
            im->alpha[im->transparent] = gdAlphaOpaque;
        }
        im->alpha[color] = gdAlphaTransparent;
    }
    im->transparent = color;
}