BGD_DECLARE(void) gdImageFilledEllipse (gdImagePtr im, int mx, int my, int w, int h, int c)
{
if (im == NULL || mx < 0 || my < 0 || w <= 0 || h <= 0 || c < 0 || mx > im->sx || my > im->sy || mx + w > im->sx || my + h > im->sy)
return;
//... rest of the function
}