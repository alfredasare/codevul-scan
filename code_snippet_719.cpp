XcursorImage* XcursorImageCreate(int width, int height)
{
    XcursorImage *image;

    image = malloc (sizeof (XcursorImage) +
                   width * height * sizeof (XcursorPixel));
    if (!image)
        return NULL;
    else
    {
        image->height = height;
        image->width = width; /* Initialize width field */
        image->delay = 0;
        return image;
    }
}