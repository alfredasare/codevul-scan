static int f2fs_write_node_page(struct page *page, struct writeback_control *wbc)
{
	if (wbc && wbc->sync_point)
		return __write_node_page(page, false, NULL, wbc);
	else
		return -EINVAL;
}