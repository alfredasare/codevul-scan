static inline void v4l_print_pix_fmt(struct video_device *vfd, struct v4l2_pix_format *fmt)
{
    char format_str[64];
    sprintf(format_str, "width=%d, height=%d, format=0x%x, field=%s\n",
            fmt->width, fmt->height, fmt->pixelformat, prt_names(fmt->field, v4l2_field_names));
    dbgarg2(format_str);
}