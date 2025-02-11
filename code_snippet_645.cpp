static void nf_tables_abort_release(struct nft_trans *trans)
{
	if (!trans)
		return;

	switch (trans->msg_type) {
	case NFT_MSG_NEWTABLE:
		if (!trans->ctx)
			break;
		nf_tables_table_destroy(&trans->ctx);
		break;
	case NFT_MSG_NEWCHAIN:
		if (!trans->ctx.chain)
			break;
		nf_tables_chain_destroy(trans->ctx.chain);
		break;
	case NFT_MSG_NEWRULE:
		if (!trans->ctx.rule)
			break;
		nf_tables_rule_destroy(&trans->ctx, nft_trans_rule(trans));
		break;
	case NFT_MSG_NEWSET:
		if (!nft_trans_set(trans))
			break;
		nft_set_destroy(nft_trans_set(trans));
		break;
	}
	kfree(trans);
}