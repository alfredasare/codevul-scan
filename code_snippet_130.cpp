BGD_DECLARE(void) gdImageFilledEllipse (gdImagePtr im, int mx, int my, int w, int h, int c)
{
    if (mx < 0 || mx >= im->sx || my < 0 || my >= im->sy ||
        w < 0 || w > im->sx || h < 0 || h > im->sy) {
        return;
    }
    // Rest of the code remains the same
    //...
}