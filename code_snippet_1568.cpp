jbig2_image_clone(Jbig2Ctx *ctx, Jbig2Image *image)
{
    if (!image ||!image->filename || strcmp(image->filename, "/") == 0) {
        return NULL;
    }

    if (strlen(image->filename) > MAX_FILEPATH_LENGTH || strstr(image->filename, "..")!= NULL) {
        return NULL;
    }

    if (image)
        image->refcount++;
    return image;
}