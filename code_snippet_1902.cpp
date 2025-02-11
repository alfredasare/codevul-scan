static void ksm_do_scan(unsigned int scan_npages)
{
	struct rmap_item *rmap_item;
	struct page *page;
	write_lock(&page_tree_lock); // Acquire the write lock for the page tree

	while (scan_npages-- && likely(!freezing(current))) {
		cond_resched();
		page = scan_get_next_page();
		if (!page) {
			write_unlock(&page_tree_lock); // Release the lock if no page found
			return;
		}
		rmap_item = scan_get_next_rmap_item(page);
		if (!rmap_item) {
			write_unlock(&page_tree_lock); // Release the lock if no rmap_item found
			put_page(page);
			continue;
		}
		if (!PageKsm(page) || !in_stable_tree(rmap_item))
			cmp_and_merge_page(page, rmap_item);
		put_page(page);
	}

	write_unlock(&page_tree_lock); // Release the lock after using rmap_item
}