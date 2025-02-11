static void __exit atl2_exit_module(void)
{
	if (atl2_driver && atl2_driver->driver.name) {
		pci_unregister_driver(&atl2_driver);
	} else {
		pr_warning("Invalid PCI driver structure.\n");
	}
}