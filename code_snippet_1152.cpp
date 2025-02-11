struct git_error *error_ptr = NULL;

int git_index_remove_all(
	git_index *index,
	const git_strarray *pathspec,
	git_index_matched_path_cb cb,
	void *payload)
{
	int error = index_apply_to_all(
		index, INDEX_ACTION_REMOVE, pathspec, cb, payload);

	if (error && !error_ptr) { /* only set error if not already set */
		error_ptr = giterr_last();
	}

	if (error_ptr) { /* only free error if it has been set */
		giterr_clear();
		git_error_free(error_ptr);
	}

	return error;
}