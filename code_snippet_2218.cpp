ext4_xattr_ibody_list(struct dentry *dentry, char *buffer, int32_t buffer_size)
{
    //...
    int error = ext4_xattr_list_entries(dentry, IFIRST(header),
                                         buffer, buffer_size);
    //...
    if (buffer_size > INT_MAX) {
        error = -EOVERFLOW;
        goto cleanup;
    }
    //...
}