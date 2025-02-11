hfs_write_data_block(struct archive_write_disk *a, const char *buff, size_t size)
{
    if (size > 0 && buff != NULL) {
        return (write_data_block(a, buff, size > INT_MAX ? INT_MAX : size));
    } else {
        return -1;
    }
}