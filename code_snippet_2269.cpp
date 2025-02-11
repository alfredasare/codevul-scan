static void __exit atl2_exit_module(void)
{
    int ret;

    ret = pci_unregister_driver(&atl2_driver);
    if (ret != 0) {
        printk(KERN_ERR "atl2: Failed to unregister driver: %d\n", ret);
        return;
    }
}