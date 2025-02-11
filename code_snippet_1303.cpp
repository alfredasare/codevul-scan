static ssize_t vfs_pwrite_fn(void *file, const void *buf, size_t len, off_t offset)
{
    struct files_struct *fsp = (struct files_struct *)file;
    size_t max_len = PAGE_SIZE; // adjust the max_len according to your system's requirements

    if (len > max_len) {
        return -EOVERFLOW;
    }

    if (offset < 0 || offset > fsp->file_size) {
        return -EINVAL;
    }

    char buffer[max_len];
    ssize_t result = 0;

    if (len > 0) {
        result = memcpy(buffer, buf, len);
    }

    return SMB_VFS_PWRITE(fsp, buffer, result, offset);
}