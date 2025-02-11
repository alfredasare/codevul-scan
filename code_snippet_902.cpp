rio_exit (void)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,27)
	if (pci_driver_me(&rio_driver))
		pci_unregister_driver (&rio_driver);
#else
	if (&rio_driver)
		pci_unregister_driver (&rio_driver);
#endif
}