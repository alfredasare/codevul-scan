enum ovl_path_type ovl_path_type(struct dentry *dentry)
{
    struct ovl_entry *oe = dentry->d_fsdata;
    size_t upper_len, lower_len;

    if (oe->__upperdentry) {
        upper_len = strlen(oe->__upperdentry->d_name);
        if (oe->lowerdentry) {
            lower_len = strlen(oe->lowerdentry->d_name);
            if (S_ISDIR(dentry->d_inode->i_mode)) {
                if (upper_len + lower_len + 1 <= PATH_MAX) {
                    return OVL_PATH_MERGE;
                } else {
                    return OVL_PATH_ERROR;
                }
            } else {
                if (upper_len <= PATH_MAX) {
                    return OVL_PATH_UPPER;
                } else {
                    return OVL_PATH_ERROR;
                }
            }
        } else {
            if (upper_len <= PATH_MAX) {
                return OVL_PATH_UPPER;
            } else {
                return OVL_PATH_ERROR;
            }
        }
    } else {
        return OVL_PATH_LOWER;
    }
}