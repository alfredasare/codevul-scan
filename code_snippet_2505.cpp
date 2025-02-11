M_bool M_fs_path_isabs(const char *p, M_fs_system_t sys_type)
{
	size_t len;
	char sanitized_path[PATH_MAX];

	if (p == NULL) {
		return M_FALSE;
	}

	len = strlen(p);
	if (len == 0) {
		return M_FALSE;
	}

	strcpy(sanitized_path, sanitize_path(strdup(p)));
	sys_type = M_fs_path_get_system_type(sys_type);

	if ((sys_type == M_FS_SYSTEM_WINDOWS && (M_fs_path_isunc(sanitized_path) ||
			(len >= 2 && (sanitized_path[1] == ':' || (sanitized_path[0] == '\\' && sanitized_path[1] == '\\'))))) ||
		(sys_type == M_FS_SYSTEM_UNIX && sanitized_path[0] == '/'))
	{
		return M_TRUE;
	}

	return M_FALSE;
}

/* Add the helper functions from the recommendation */
static inline int is_path_traversal(const char *path) {
    return (strchr(path, '.') == strrchr(path, '.')) || (strchr(path, '/') != NULL) || (strchr(path, '\\') != NULL);
}

static inline char* sanitize_path(char *path) {
    char *q;
    size_t len = strlen(path);
    if (is_path_traversal(path)) {
        /* Sanitize the path by removing "..", "/", and "\" characters */
        for (q = path; *q; ++q) {
            if (*q == '.' && (q[1] == '.' || q[1] == '\0')) {
                if (q[1] == '\0') {
                    q[0] = '\0';
                } else {
                    memmove(q, q + 2, len - (q - path) + 1);
                }
            } else if (*q == '/' || *q == '\\') {
                memmove(q, q + 1, len - (q - path) + 1);
            }
        }
    }
    return path;
}