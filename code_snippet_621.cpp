void drm_crtc_init(struct drm_device *dev, struct drm_crtc *crtc,
		   const struct drm_crtc_funcs *funcs)
{
    crtc->dev = dev;
    crtc->funcs = funcs;

    struct drm_mode_object *obj = drm_mode_object_create(dev, DRM_MODE_OBJECT_CRTC);
    if (!obj) {
        return;
    }

    if (obj->handle < 0 || obj->handle >= dev->mode_config.num_crtc_objects) {
        drm_mode_object_free(dev, obj);
        return;
    }

    drm_mode_object_get(dev, obj, DRM_MODE_OBJECT_CRTC);
    list_add_tail(&crtc->head, &dev->mode_config.crtc_list);
    dev->mode_config.num_crtc++;
}