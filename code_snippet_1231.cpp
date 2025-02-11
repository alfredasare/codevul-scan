static inline struct device *vop_dev(struct vop_vdev *vdev)
{
    char *path = vdev->vpdev->dev.parent->driver->bus_id;
    int i = 0;

    // Check for path traversal characters
    while ((path[i] == '.' && i > 0) || path[i] == '/') {
        i++;
    }
    path[i] = '\0';

    return vdev->vpdev->dev.parent;
}