static void scsi_write_complete(void *opaque, int ret)
{
    //...
    if (r->iov.iov_len > 0) {
        char *iov_ptr = r->iov.iov_base;
        size_t iov_len = r->iov.iov_len;

        while (iov_len > 0) {
            if (strchrnul(iov_ptr, '/')!= iov_ptr && strchr(iov_ptr, '..')!= NULL) {
                // Found invalid character, truncate iov structure
                iov_len = iov_ptr - iov_base + strlen(iov_ptr);
                break;
            }
            iov_ptr++;
            iov_len--;
        }

        if (iov_len > 0) {
            r->iov.iov_len = iov_len;
            r->iov.iov_base = iov_base;
        } else {
            // Return error or truncate iov structure
            return;
        }
    }
    //...
}