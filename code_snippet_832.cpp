vpx_image_t *vpx_img_alloc(vpx_image_t *img, vpx_img_fmt_t fmt,
                           unsigned int d_w, unsigned int d_h,
                           unsigned int align) {
    vpx_image_t *allocated_img = img_alloc_helper(img, fmt, d_w, d_h, align, align, NULL);
    if (allocated_img == NULL || d_w > allocated_img->d_w || d_h > allocated_img->d_h) {
        if (allocated_img != NULL) free(allocated_img);
        return NULL;
    }
    return allocated_img;
}