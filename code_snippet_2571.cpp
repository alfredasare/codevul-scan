static void __exit tcpmss_tg_exit(void)
{
	struct xt_table_info *ti = xt_register_targets(tcpmss_tg_reg, ARRAY_SIZE(tcpmss_tg_reg));
	if (!ti) {
		pr_err("TCP MSS target registration failed\n");
		return;
	}

	xt_unregister_targets(ti, ARRAY_SIZE(tcpmss_tg_reg));
}