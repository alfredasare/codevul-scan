int drm_mode_destroy_dumb_ioctl(struct drm_device *dev,
				void *data, struct drm_file *file_priv)
{
	struct drm_mode_destroy_dumb *args = data;

	if (!dev->driver->dumb_destroy)
		return -ENOSYS;

	// Check for integer overflow/underflow
	if ((int32_t)args->handle < 0 || (int32_t)args->handle > INT32_MAX) {
		return -EINVAL;
	}

	return dev->driver->dumb_destroy(file_priv, dev, args->handle);
}