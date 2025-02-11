static int compat_copy_entries(unsigned char *data, unsigned int size_user,
			       struct ebt_entries_buf_state *state)
{
	unsigned int size_remaining = size_user;
	int ret;

	/* Validate size_user to prevent buffer overflow */
	if (size_user > EBT_MAX_BUFFER_SIZE) {
		err("Invalid size_user value: %u", size_user);
		return -EINVAL;
	}

	ret = EBT_ENTRY_ITERATE(data, size_user, size_entry_mwt, data,
					&size_remaining, state);
	if (ret < 0)
		return ret;

	WARN_ON(size_remaining);
	return state->buf_kern_offset;
}