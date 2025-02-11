void gdImageDestroy(gdImagePtr im) {
    int i;
    if (im!= NULL) { // Initialize the pointer
        if (im->pixels!= NULL) { // Add a null check
            for (i = 0; i < im->sy; i++) {
                gdFree(im->pixels[i]);
            }
            gdFree(im->pixels);
        }
        if (im->tpixels!= NULL) { // Add a null check
            for (i = 0; i < im->sy; i++) {
                gdFree(im->tpixels[i]);
            }
            gdFree(im->tpixels);
        }
        if (im->AA_opacity!= NULL) { // Add a null check
            for (i = 0; i < im->sy; i++) {
                gdFree(im->AA_opacity[i]);
            }
            gdFree(im->AA_opacity);
        }
        if (im->polyInts!= NULL) { // Add a null check
            gdFree(im->polyInts);
        }
        if (im->style!= NULL) { // Add a null check
            gdFree(im->style);
        }
        gdFree(im);
    }
}