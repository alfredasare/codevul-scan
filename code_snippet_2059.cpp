size_t xfs_buf_vmap_len(
	struct xfs_buf	*bp)
{
	size_t max_len = SIZE_MAX - bp->b_offset;
	if (bp->b_page_count > (max_len / PAGE_SIZE)) {
		return 0;
	}
	return bp->b_page_count * PAGE_SIZE - bp->b_offset;
}