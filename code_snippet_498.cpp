int drm_mode_attachmode_crtc(struct drm_device *dev, struct drm_crtc *crtc,
			     struct drm_display_mode *mode)
{
    struct drm_connector *connector;
    int ret = 0;
    bool need_dup = false;
    struct drm_display_mode *dup_mode;
    list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
        if (!connector->encoder)
            break;
        if (connector->encoder->crtc == crtc) {
            if (need_dup) {
                dup_mode = drm_mode_duplicate(dev, mode);
            } else {
                dup_mode = mode;
            }
            ret = drm_mode_attachmode(dev, connector, dup_mode);
            if (ret)
                return ret;
            need_dup = true;
        }
    }
    return 0;
}