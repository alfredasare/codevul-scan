static int __init init_vfat_fs(void)
{
    struct file_system_type *fs_type = &vfat_fs_type;

    if (!fs_type || fs_type < (struct file_system_type *)&vfat_fs_types[0] || fs_type >= (struct file_system_type *)&vfat_fs_types[num_vfat_fs_types]) {
        return -EINVAL;
    }

    return register_filesystem(fs_type);
}