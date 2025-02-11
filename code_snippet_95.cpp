static int __net_init raw6_init_net(struct net *net)
{
    int ret = 0;

    if ((ret = proc_create("raw6", S_IRUGO, net->proc_net, &raw6_seq_fops)) < 0) {
        net_err(KERN_WARNING "Failed to create raw6 proc entry\n");
        return -EIO;
    }

    return 0;
}