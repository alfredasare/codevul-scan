static void prpl_xfer_accept(struct file_transfer *ft)
{
	struct prpl_xfer_data *px = ft->data;

        if (!px || !px->xfer) {
                purple_debug_error("your_module", "Null pointer detected! px: %p, px->xfer: %p\n", px, px->xfer);
                return;
        }

	purple_xfer_request_accepted(px->xfer, NULL);
	prpl_xfer_write_request(ft);
}