void udp6_proc_exit(struct net *net) {
    struct seq_afinfo *afinfo = &udp6_seq_afinfo; // Initialize the pointer
    udp_proc_unregister(net, afinfo);
}