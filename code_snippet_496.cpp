static void ext4_end_io_dio(struct kiocb *iocb, loff_t offset,
			    ssize_t size, void *private)
{
	ext4_io_end_t *io_end = iocb->private;
	ext4_io_end_t *new_io_end = NULL;

	/* if not async direct IO just return */
	if (!io_end)
		return;

	ext_debug("ext4_end_io_dio(): io_end 0x%p "
		  "for inode %lu, iocb 0x%p, offset %llu, size %zd\n",
 		  iocb->private, io_end->inode->i_ino, iocb, offset,
		  size);

	new_io_end = kzalloc(sizeof(*new_io_end), GFP_KERNEL);
	if (!new_io_end) {
		pr_err("Failed to allocate memory for new_io_end\n");
		return;
	}

	/* Perform any necessary operations using the temporary variable */
	memcpy(new_io_end, io_end, sizeof(*new_io_end));
	new_io_end->offset = offset;
	new_io_end->size = size;

	/* Update iocb->private after all operations are done */
	iocb->private = new_io_end;
	ext4_put_io_end(io_end);
}