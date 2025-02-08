void fslib_duplicate(const char *full_path) {
	assert(full_path);

	struct stat s;
	if (stat(full_path, &s) != 0 || s.st_uid != 0 || access(full_path, R_OK))
		return;

	char *dest_dir = build_dest_dir(full_path);

	char *ptr = strrchr(full_path, '/');
	if (!ptr)
		return;
	ptr++;
	if (*ptr == '\0')
		return;

	char *name;
	if (asprintf(&name, "%s/%s", dest_dir, ptr) == -1)
		errExit("asprintf");
	if (stat(name, &s) == 0) {
		free(name);
		return;
	}
	free(name);

	if (arg_debug || arg_debug_private_lib)
		printf("    copying %s to private %s\n", full_path, dest_dir);

	sbox_run(SBOX_ROOT| SBOX_SECCOMP, 4, PATH_FCOPY, "--follow-link", full_path, dest_dir);
	report_duplication(full_path);
	lib_cnt++;
}
