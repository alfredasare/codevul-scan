uncompress_image(Gif_Context *gfc, Gif_Image *gfi, Gif_Reader *grr)
{
    int old_nerrors;
    if (!Gif_CreateUncompressedImage(gfi, gfi->interlace))
        return 0;

    // Validate width and height before using them
    if (gfi->width > 0 && gfi->height > 0) {
        gfc->width = gfi->width;
        gfc->height = gfi->height;
        size_t max_image_size = (size_t) gfi->width * (size_t) gfi->height;
        if (max_image_size > 0 && gfi->image_data != NULL) {
            gfc->image = gfi->image_data;
            gfc->maximage = gfi->image_data + max_image_size;
        } else {
            // Handle invalid image_data or size
            return 0;
        }
    } else {
        // Handle invalid width or height
        return 0;
    }

    old_nerrors = gfc->errors[1];
    read_image_data(gfc, grr);
    gfi->compressed_errors = gfc->errors[1] - old_nerrors;
    return 1;
}