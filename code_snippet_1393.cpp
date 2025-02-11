static void nfnl_err_del(struct nfnl_err *nfnl_err)
{
	if (!nfnl_err) {
		pr_err("Null pointer encountered in nfnl_err_del\n");
		return;
	}

	list_del(&nfnl_err->head);
	kfree(nfnl_err);
}