hfs_write_data_block(struct archive_write_disk *a, const char *buff, size_t size)
{
    char normalized_path[PATH_MAX];
    realpath(buff, normalized_path);
    if (strcmp(normalized_path, buff)!= 0) {
        // Handle the case where the normalized path is different from the original path
        // For example, log an error or return an error code
    }
    return (write_data_block(a, buff, size));
}