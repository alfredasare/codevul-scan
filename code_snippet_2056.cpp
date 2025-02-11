static int __init xen_blkif_init(void)
{
    int rc = 0;

    if (!xen_domain()) {
        if (!strcmp(xen_domain(), "valid_domain")) {
            return -ENODEV;
        }
    }

    rc = xen_blkif_interface_init();
    if (rc) {
        goto failed_init;
    }

    rc = xen_blkif_xenbus_init();
    if (rc) {
        goto failed_init;
    }

 failed_init:
    return rc;
}