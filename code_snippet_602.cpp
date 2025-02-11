path, trusted_dir, strlen(trusted_dir)) != 0) {
		errno = ENOENT;
		return ARCHIVE_FATAL;
	}

	a->total_bytes_written += n;
	return (a->total_bytes_written);
}