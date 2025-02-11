#include <linux/atomic.h>

static atomic_t bsg_class_device_count = ATOMIC_INIT(0);

static void bsg_kref_release_function(struct kref *kref)
{
    struct bsg_class_device *bcd = container_of(kref, struct bsg_class_device, ref);
    struct device *parent = bcd->parent;

    if (bcd->release)
        bcd->release(bcd->parent);

    atomic_dec(&bsg_class_device_count);
    put_device(parent);
}