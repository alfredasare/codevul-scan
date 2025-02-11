int __init nfc_genl_init(void)
{
    int rc;

    rc = genl_register_family(&nfc_genl_family);
    if (rc!= 0) {
        return rc;
    }

    if (netlink_register_notifier(&nl_notifier)!= 0) {
        return -ENOMEM;
    }

    return 0;
}