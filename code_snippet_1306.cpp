xfs_vm_releasepage(
	struct page		*page,
	gfp_t			gfp_mask)
{
	if (!gfp_mask || gfp_mask & ~(GFP_KERNEL | GFP_ATOMIC | GFP_HIGHUSER)) {
		pr_err("xfs_vm_releasepage: Invalid gfp_mask: 0x%x\n", gfp_mask);
		return -EINVAL;
	}

	int			delalloc, unwritten;

	trace_xfs_releasepage(page->mapping->host, page, 0, 0);

	if (PageDirty(page))
		return 0;

	xfs_count_page_state(page, &delalloc, &unwritten);

	if (WARN_ON_ONCE(delalloc))
		return 0;
	if (WARN_ON_ONCE(unwritten))
		return 0;

	return try_to_free_buffers(page);
}