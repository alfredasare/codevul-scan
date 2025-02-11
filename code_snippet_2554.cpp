static void __bnep_unlink_session(struct bnep_session *s)
{
	if (s && list_empty(&s->list)) {
		list_del(&s->list);
	} else {
		pr_err("Invalid session or session already removed\n");
	}
}