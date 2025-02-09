static void __nft_release_table(struct net *net, struct nft_table *table)
{
	struct nft_flowtable *flowtable, *nf;
	struct nft_chain *chain, *nc;
	struct nft_object *obj, *ne;
	struct nft_rule *rule, *nr;
	struct nft_set *set, *ns;
	struct nft_ctx ctx = {
		.net	= net,
		.family	= NFPROTO_NETDEV,
	};

	ctx.family = table->family;
	ctx.table = table;
	list_for_each_entry(chain, &table->chains, list) {
		ctx.chain = chain;
		list_for_each_entry_safe(rule, nr, &chain->rules, list) {
			list_del(&rule->list);
			chain->use--;
			nf_tables_rule_release(&ctx, rule);
		}
	}
	list_for_each_entry_safe(flowtable, nf, &table->flowtables, list) {
		list_del(&flowtable->list);
		table->use--;
		nf_tables_flowtable_destroy(flowtable);
	}
	list_for_each_entry_safe(set, ns, &table->sets, list) {
		list_del(&set->list);
		table->use--;
		nft_set_destroy(&ctx, set);
	}
	list_for_each_entry_safe(obj, ne, &table->objects, list) {
		nft_obj_del(obj);
		table->use--;
		nft_obj_destroy(&ctx, obj);
	}
	list_for_each_entry_safe(chain, nc, &table->chains, list) {
		ctx.chain = chain;
		nft_chain_del(chain);
		table->use--;
		nf_tables_chain_destroy(&ctx);
	}
	list_del(&table->list);
	nf_tables_table_destroy(&ctx);
}