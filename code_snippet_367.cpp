static void __exit ipsec_pfkey_exit(void)
{
	const int max_allowed_buffer_size = 65536; // Example maximum allowed buffer size
	int buffer_size;

	buffer_size = xfrm_get_sock_buf_size(&pfkeyv2_mgr);
	if (buffer_size <= 0 || buffer_size > max_allowed_buffer_size) {
		pr_err("Invalid buffer size: %d. Exiting...\n", buffer_size);
		return;
	}

	xfrm_unregister_km(&pfkeyv2_mgr);

	sock_unregister(PF_KEY);

	unregister_pernet_subsys(&pfkey_net_ops);

	proto_unregister(&key_proto);
}