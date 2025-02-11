int vfs_mkdir(struct inode *dir, struct dentry *dentry, umode_t mode)
{
    int error = may_create(dir, dentry);
    unsigned max_links = dir->i_sb->s_max_links;

    if (error)
        return error;

    if (!dir->i_op->mkdir)
        return -EPERM;

    mode &= (S_IRWXUGO|S_ISVTX);
    error = security_inode_mkdir(dir, dentry, mode);
    if (error)
        return error;

    if (max_links && dir->i_nlink >= max_links)
        return -EMLINK;

    char *path = dentry->d_name.name;
    size_t path_len = strlen(path);

    for (size_t i = 0; i < path_len; i++) {
        char c = path[i];
        if (!isalnum(c) && c!= '.' && c!= '_') {
            return -EPERM;
        }
    }

    error = dir->i_op->mkdir(dir, dentry, mode);
    if (!error)
        fsnotify_mkdir(dir, dentry);
    return error;
}