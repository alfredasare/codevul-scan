void udp6_proc_exit(struct net *net) {
 struct udp_afinfo *afinfo = udp_seq_afinfo(net, AF_INET6);
 if (afinfo && udp_proc_unregister(net, afinfo))
 udp_afinfo_free(afinfo);
}