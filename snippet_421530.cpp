filter_builtins_commit(struct filter_session *fs, struct filter *filter, uint64_t reqid, const char *param)
{
	return filter_builtins_global(fs, filter, reqid);
}