XcursorImage* XcursorImageCreate(size_t width, size_t height) {
    XcursorImage* image;

    if (width > SIZE_MAX / sizeof(XcursorPixel) || height > SIZE_MAX / sizeof(XcursorPixel)) {
        // Handle error or return an error value
    }

    image = malloc((size_t)width * height * sizeof(XcursorPixel));
    if (!image) {
        // Handle error or return an error value
    }
    image->height = height;
    image->delay = 0;
    return image;
}