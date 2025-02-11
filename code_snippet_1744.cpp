static struct dentry *ovl_mount(struct file_system_type *fs_type, int flags,
                                const char *dev_name, void *raw_data)
{
    if (!raw_data) {
        return ERR_PTR(-EINVAL);
    }

    return mount_nodev(fs_type, flags, raw_data, ovl_fill_super);
}