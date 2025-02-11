static int __init xen_blkif_init(void)
{
	int rc = 0;

	if (!xen_domain())
		return -ENODEV;

	rc = xen_blkif_interface_init();
	if (rc)
		goto cleanup_interface;

	rc = xen_blkif_xenbus_init();
	if (rc)
		goto cleanup_interface;

	/* No errors, return successfully */
	return 0;

cleanup_interface:
	xen_blkif_interface_cleanup(); /* Release resources allocated by xen_blkif_interface_init */
	return rc;
}