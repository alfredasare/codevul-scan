int drm_mode_attachmode_crtc(struct drm_device *dev, struct drm_crtc *crtc,
                             struct drm_display_mode *mode)
{
        struct drm_connector *connector;
        int ret = 0;
        list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
                if (!connector->encoder)
                        break;
                if (connector->encoder->crtc == crtc) {
                        struct drm_display_mode *dup_mode = NULL;
                        int need_dup = !connector->mode_equals(connector, mode);

                        if (need_dup) {
                                dup_mode = drm_mode_duplicate(dev, mode);
                                if (!dup_mode)
                                        return -ENOMEM;
                        }

                        ret = drm_mode_attachmode(dev, connector, need_dup ? dup_mode : mode);
                        if (ret)
                                return ret;

                        if (need_dup)
                                drm_mode_put(dev, dup_mode);
                }
        }
        return 0;
}