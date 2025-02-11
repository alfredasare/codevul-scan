static int vivid_fb_blank(int blank_mode, struct fb_info *info)
{
    struct vivid_dev *dev = (struct vivid_dev *)info->par;

    dev_dbg(dev, "Blanking mode set to %d\n");
    switch (blank_mode) {
        case FB_BLANK_UNBLANK:
            break;
        case FB_BLANK_NORMAL:
        case FB_BLANK_HSYNC_SUSPEND:
        case FB_BLANK_VSYNC_SUSPEND:
        case FB_BLANK_POWERDOWN:
            break;
    }
    return 0;
}