static int vivid_fb_blank(int blank_mode, struct fb_info *info)
{
	struct vivid_dev *dev = (struct vivid_dev *)info->par;

	if (blank_mode < FB_BLANK_UNBLANK || blank_mode > FB_BLANK_POWERDOWN) {
		pr_warn("%s: Invalid blank_mode (%d)\n", __func__, blank_mode);
		return -EINVAL;
	}

	dprintk(dev, 1, "Set blanking mode : %d\n", blank_mode);
	switch (blank_mode) {
	case FB_BLANK_UNBLANK:
	case FB_BLANK_NORMAL:
	case FB_BLANK_HSYNC_SUSPEND:
	case FB_BLANK_VSYNC_SUSPEND:
	case FB_BLANK_POWERDOWN:
		break;
	default:
		return -EINVAL;
	}

	return 0;
}