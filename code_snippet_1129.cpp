xfs_vm_releasepage(
	struct page		*page,
	gfp_t			gfp_mask)
{
	int			delalloc, unwritten;

	trace_xfs_releasepage(page->mapping->host, page, 0, 0);

	if (xfs_buffer_fstimeo(page->mapping->host, page)!= page->private)
		return 0;

	xfs_count_page_state(page, &delalloc, &unwritten);

	if (WARN_ON_ONCE(delalloc))
		return 0;
	if (WARN_ON_ONCE(unwritten))
		return 0;

	return try_to_free_buffers(page);
}