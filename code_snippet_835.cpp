static int do_sysfs_registration(void)
{
    int rc;
    struct kobject *fs_kobj = NULL;

    fs_kobj = kobject_create_and_add("ecryptfs", NULL);
    if (!fs_kobj) {
        printk(KERN_ERR "Unable to create ecryptfs kset\n");
        rc = -ENOMEM;
        goto out;
    }
    rc = sysfs_create_group(fs_kobj, &attr_group);
    if (rc) {
        printk(KERN_ERR "Unable to create ecryptfs version attributes\n");
        kobject_put(fs_kobj);
    }
out:
    return rc;
}