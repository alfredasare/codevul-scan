int is_dir(const char *fname) {
	assert(fname);
	if (*fname == '\0')
		return 0;

	int rv;
	struct stat s;

	// Validate the input to prevent path traversal (CWE-269, CVE-2017-5940)
	if (strchr(fname, '/') || strchr(fname, '\\'))
		return 0;

	if (*(fname + strlen(fname) - 1) == '/')
		rv = stat(fname, &s);
	else {
		char tmp[strlen(fname) + 2]; // Use a fixed buffer for safety
		strcpy(tmp, fname);
		strcat(tmp, "/");
		rv = stat(tmp, &s);
	}

	if (rv == -1)
		return 0;

	if (S_ISDIR(s.st_mode))
		return 1;

	return 0;
    }