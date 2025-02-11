pr_err("macvtap: register_netdevice_notifier failed\n");
class_unregister(macvtap_class);
cdev_del(&macvtap_cdev);
unregister_chrdev_region(macvtap_major, MACVTAP_NUM_DEVS);
return err;
}

err = macvlan\_link\_register(&macvtap\_link\_ops);
if (err) {
pr\_err("macvtap: macvlan\_link\_register failed\n");
unregister\_netdevice\_notifier(&macvtap\_notifier\_block);
class\_unregister(macvtap\_class);
cdev\_del(&macvtap\_cdev);
unregister\_chrdev\_region(macvtap\_major, MACVTAP\_NUM\_DEVS);
return err;
}

return 0;
}