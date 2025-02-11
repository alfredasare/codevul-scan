static inline struct device *vop_dev(struct vop_vdev *vdev)
{
	if (!vdev || !vdev->vpdev) {