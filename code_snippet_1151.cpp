const char *vfs_readdirname(connection_struct *conn, void *p, SMB_STRUCT_STAT *sbuf, char **talloced) {
   ...
    status = SMB_VFS_TRANSLATE_NAME(conn, dname, vfs_translate_to_windows, talloc_tos(), &translated);
    if (!NT_STATUS_IS_OK(status)) {
        if (translated!= NULL) {
            talloc_free(translated);
        }
        *talloced = NULL;
        return NULL;
    }
    *talloced = translated;
    return translated;
}