const char *vfs_readdirname(connection_struct *conn, void *p,
                             SMB_STRUCT_STAT *sbuf, char **talloced)
{
	struct dirent *ptr= NULL;
	const char *dname;
	char *translated;
	size_t translated_len;
	NTSTATUS status;

	if (!p)
		return(NULL);

	ptr = SMB_VFS_READDIR(conn, (DIR *)p, sbuf);
	if (!ptr)
		return(NULL);

	dname = ptr->d_name;

	status = SMB_VFS_TRANSLATE_NAME(conn, dname, vfs_translate_to_windows,
					talloc_tos(), &translated);

	if (NT_STATUS_EQUAL(status, NT_STATUS_NONE_MAPPED)) {
		*talloced = NULL;
		return dname;
	}

	translated_len = strlen(translated);
	if ((*talloced = talloc_realloc(NULL, *talloced, char, translated_len + 1)) == NULL)
		return NULL;

	strncpy(*talloced, translated, translated_len + 1);
	talloc_free(translated);

	if (!NT_STATUS_IS_OK(status)) {
		return NULL;
	}
	return *talloced;
}