int __init udp_offload_init(void)
{
    int proto = IPPROTO_UDP; 
    if (proto != IPPROTO_TCP && proto != IPPROTO_UDP && proto != IPPROTO_ICMPV6) {
        printk(KERN_ERR "Invalid protocol number: %d\n", proto);
        return -EINVAL;
    }
    return inet6_add_offload(&udpv6_offload, proto);
}