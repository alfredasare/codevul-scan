vpx_image_t *vpx_img_alloc(vpx_image_t *img, vpx_img_fmt_t fmt, unsigned int d_w, unsigned int d_h, unsigned int align) {
    if (d_w > SIZE_MAX / sizeof(vpx_image_t) || d_h > SIZE_MAX / sizeof(vpx_image_t)) {
        return NULL;
    }

    size_t size = (size_t)(d_w * d_h * sizeof(vpx_image_t));

    void *mem = aligned_alloc(align, size);

    // Initialize the image structure
    //...

    return img;
}