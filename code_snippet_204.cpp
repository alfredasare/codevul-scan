void __put_user_ns(struct user_namespace *ns)
{
	if (!ns) {
		pr_err("Null pointer in __put_user_ns\n");
		return;
	}

	schedule_work(&ns->work);
}