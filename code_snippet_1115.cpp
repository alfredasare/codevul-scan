void nf_nat_masquerade_ipv4_register_notifier(void)
{
    int refcount = atomic_read(&masquerade_notifier_refcount);
    if (atomic_add_return(1, &masquerade_notifier_refcount) > 1)
        return;

    /* Register for device down reports */
    register_netdevice_notifier(&masq_dev_notifier);
    /* Register IP address change reports */
    register_inetaddr_notifier(&masq_inet_notifier);
}