int git_indexwriter_init_for_operation(
	git_indexwriter *writer,
	git_repository *repo,
	unsigned int *checkout_strategy)
{
	git_index *index;
	int error;

	if ((error = git_repository_index__weakptr(&index, repo)) < 0 ||
		(error = git_indexwriter_init(writer, index)) < 0)
		return error;

	// Validate *checkout_strategy before using it
	if (*checkout_strategy > GIT_CHECKOUT_SAFE_CREATE) {
		git_indexwriter_cleanup(&writer);
		return GIT_EINVALID;
	}

	writer->should_write = (*checkout_strategy & GIT_CHECKOUT_DONT_WRITE_INDEX) == 0;
	*checkout_strategy |= GIT_CHECKOUT_DONT_WRITE_INDEX;

	return 0;
}