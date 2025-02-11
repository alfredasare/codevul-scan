static void bsg_kref_release_function(struct kref *kref)
{
	struct bsg_class_device *bcd =
		container_of(kref, struct bsg_class_device, ref);
	struct device *parent = bcd->parent;

	if (bcd->release) {
		put_device(parent);
		bcd->release(parent);
	} else {
		put_device(parent);
	}
}