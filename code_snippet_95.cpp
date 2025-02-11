static int __net_init raw6_init_net(struct net *net)
{
	if (!proc_create_data("raw6", 0600, net->proc_net, &raw6_seq_fops, NULL))
		return -ENOMEM;

	return 0;
}