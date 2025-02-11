void gdImageDestroy (gdImagePtr im)
{
        int i;
        if (im != NULL) {
                if (im->pixels != NULL) {
                        for (i = 0; i < im->sy; i++) {
                                gdFree(im->pixels[i]);
                        }
                        gdFree(im->pixels);
                }
                if (im->tpixels != NULL) {
                        for (i = 0; i < im->sy; i++) {
                                gdFree(im->tpixels[i]);
                        }
                        gdFree(im->tpixels);
                }
                if (im->AA_opacity != NULL) {
                        for (i = 0; i < im->sy; i++) {
                                gdFree(im->AA_opacity[i]);
                        }
                        gdFree(im->AA_opacity);
                }
                if (im->polyInts != NULL) {
                        gdFree(im->polyInts);
                }
                if (im->style != NULL) {
                        gdFree(im->style);
                }
                gdFree(im);
        }
}