int __init bnep_sock_init(void)
{
	int err;

	if (bt_sock_family_ops == NULL) {
		BT_ERR("bnep_sock_family_ops is NULL");
		return -EINVAL;
	}

	err = proto_register(&bnep_proto, 0);
	if (err < 0)
		return err;

	err = bt_sock_register(BTPROTO_BNEP, &bnep_sock_family_ops);
	if (err < 0) {
		BT_ERR("Can't register BNEP socket");
		proto_unregister(&bnep_proto);
	}
	return err;
}