static void pcd_release(struct cdrom_device_info *cdi)
{
    if (cdi == NULL) {
        printk(KERN_ERR "pcd_release: invalid cdrom device info\n");
        return;
    }

    if (cdi->device_name!= NULL) {
        // Release resources associated with cdi->device_name
    }
    //...
}