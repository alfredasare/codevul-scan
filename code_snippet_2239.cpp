static void prpl_xfer_accept(struct file_transfer *ft)
{
    struct prpl_xfer_data *px = ft->data;
    char buffer[1024];

    if (px->xfer->size > sizeof(buffer)) {
        // Handle error or return an error code
    }

    if (strlen(px->xfer->data) > sizeof(buffer)) {
        // Handle error or return an error code
    }

    strncpy(buffer, px->xfer->data, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    purple_xfer_request_accepted(px->xfer, NULL);
    prpl_xfer_write_request(ft);
}