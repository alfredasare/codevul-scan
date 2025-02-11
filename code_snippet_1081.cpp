static bool check_underflow(const struct ip6t_entry *e)
{
	const struct xt_entry_target *t;
	unsigned int verdict;
	long long wide_verdict;

	if (!unconditional(&e->ipv6))
		return false;
	t = ip6t_get_target_c(e);
	if (strcmp(t->u.user.name, XT_STANDARD_TARGET) != 0)
		return false;
	verdict = ((struct xt_standard_target *)t)->verdict;
	wide_verdict = -verdict - 1;

	if (wide_verdict < NF_MIN || wide_verdict > NF_MAX)
		return false;

	return wide_verdict == NF_DROP || wide_verdict == NF_ACCEPT;
}