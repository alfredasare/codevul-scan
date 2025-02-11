``c
static inline void v4l_print_pix_fmt(struct video_device *vfd, struct v4l2_pix_format *fmt)
{
	if (fmt->width > 0 && fmt->width <= INT_MAX / fmt->bytesperline &&
	    fmt->bytesperline > 0 && fmt->bytesperline <= INT_MAX / fmt->height &&
	    fmt->height > 0 && fmt->height <= ((INT_MAX - fmt->bytesperline) / fmt->width)) {
		dbgarg2("width=%d, height=%d, format=%c%c%c%c, field=%s, "
			"bytesperline=%d sizeimage=%d, colorspace=%d\n",
			fmt->width, fmt->height,
			(fmt->pixelformat & 0xff),
			(fmt->pixelformat >>  8) & 0xff,
			(fmt->pixelformat >> 16) & 0xff,
			(fmt->pixelformat >> 24) & 0xff,
			prt_names(fmt->field, v4l2_field_names),
			fmt->bytesperline,
			fmt->bytesperline * fmt->height,
			fmt->colorspace);
	} else {
		pr_err("Invalid pixelformat dimensions\n");
	}
};