void md_kick_rdev_from_array(struct md_rdev *rdev)
{
    if (!rdev) {
        printk(KERN_ERR "md_kick_rdev_from_array: invalid rdev pointer\n");
        return;
    }

    unbind_rdev_from_array(rdev);
    export_rdev(rdev);
}