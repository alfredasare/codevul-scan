static int v4l_g_fmt(const struct v4l2_ioctl_ops *ops,
				struct file *file, void *fh, void *arg)
{
	struct v4l2_format *p = arg;
	struct video_device *vfd = video_devdata(file);
	int ret = check_fmt(file, p->type);

	if (ret)
		return ret;

	/*
	 * fmt can't be cleared for these overlay types due to the 'clips'
	 * 'clipcount' and 'bitmap' pointers in struct v4l2_window.
	 * Those are provided by the user. So handle these two overlay types
	 * first, and then just do a simple memset for the other types.
	 */
	switch (p->type) {
	case V4L2_BUF_TYPE_VIDEO_OVERLAY:
	case V4L2_BUF_TYPE_VIDEO_OUTPUT_OVERLAY: {
		struct v4l2_clip *clips = p->fmt.win.clips;
		u32 clipcount = p->fmt.win.clipcount;
		void __user *bitmap = p->fmt.win.bitmap;

		memset(&p->fmt, 0, sizeof(p->fmt));
		p->fmt.win.clips = clips;
		p->fmt.win.clipcount = clipcount;
		p->fmt.win.bitmap = bitmap;
		break;
	}
	default:
		memset(&p->fmt, 0, sizeof(p->fmt));
		break;
	}

	switch (p->type) {
	case V4L2_BUF_TYPE_VIDEO_CAPTURE:
		if (unlikely(!ops->vidioc_g_fmt_vid_cap))
			break;
		p->fmt.pix.priv = V4L2_PIX_FMT_PRIV_MAGIC;
		ret = ops->vidioc_g_fmt_vid_cap(file, fh, arg);
		/* just in case the driver zeroed it again */
		p->fmt.pix.priv = V4L2_PIX_FMT_PRIV_MAGIC;
		if (vfd->vfl_type == VFL_TYPE_TOUCH)
			v4l_pix_format_touch(&p->fmt.pix);
		return ret;
	case V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE:
		return ops->vidioc_g_fmt_vid_cap_mplane(file, fh, arg);
	case V4L2_BUF_TYPE_VIDEO_OVERLAY:
		return ops->vidioc_g_fmt_vid_overlay(file, fh, arg);
	case V4L2_BUF_TYPE_VBI_CAPTURE:
		return ops->vidioc_g_fmt_vbi_cap(file, fh, arg);
	case V4L2_BUF_TYPE_SLICED_VBI_CAPTURE:
		return ops->vidioc_g_fmt_sliced_vbi_cap(file, fh, arg);
	case V4L2_BUF_TYPE_VIDEO_OUTPUT:
		if (unlikely(!ops->vidioc_g_fmt_vid_out))
			break;
		p->fmt.pix.priv = V4L2_PIX_FMT_PRIV_MAGIC;
		ret = ops->vidioc_g_fmt_vid_out(file, fh, arg);
		/* just in case the driver zeroed it again */
		p->fmt.pix.priv = V4L2_PIX_FMT_PRIV_MAGIC;
		return ret;
	case V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE:
		return ops->vidioc_g_fmt_vid_out_mplane(file, fh, arg);
	case V4L2_BUF_TYPE_VIDEO_OUTPUT_OVERLAY:
		return ops->vidioc_g_fmt_vid_out_overlay(file, fh, arg);
	case V4L2_BUF_TYPE_VBI_OUTPUT:
		return ops->vidioc_g_fmt_vbi_out(file, fh, arg);
	case V4L2_BUF_TYPE_SLICED_VBI_OUTPUT:
		return ops->vidioc_g_fmt_sliced_vbi_out(file, fh, arg);
	case V4L2_BUF_TYPE_SDR_CAPTURE:
		return ops->vidioc_g_fmt_sdr_cap(file, fh, arg);
	case V4L2_BUF_TYPE_SDR_OUTPUT:
		return ops->vidioc_g_fmt_sdr_out(file, fh, arg);
	case V4L2_BUF_TYPE_META_CAPTURE:
		return ops->vidioc_g_fmt_meta_cap(file, fh, arg);
	case V4L2_BUF_TYPE_META_OUTPUT:
		return ops->vidioc_g_fmt_meta_out(file, fh, arg);
	}
	return -EINVAL;
}