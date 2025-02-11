static bool is_dump_unreclaim_slabs(void)
{
	unsigned long max_size = sizeof(nr_lru) * CHAR_BIT * sizeof(unsigned long);
	unsigned long nr_lru = 0;

	nr_lru += global_node_page_state(NR_ACTIVE_ANON);
	nr_lru += global_node_page_state(NR_INACTIVE_ANON);
	nr_lru += global_node_page_state(NR_ACTIVE_FILE);
	nr_lru += global_node_page_state(NR_INACTIVE_FILE);
	nr_lru += global_node_page_state(NR_ISOLATED_ANON);
	nr_lru += global_node_page_state(NR_ISOLATED_FILE);
	nr_lru += global_node_page_state(NR_UNEVICTABLE);

	if (nr_lru > max_size) {
		// Handle error condition
		// Log an error message or take appropriate action
		return false;
	}

	return (global_node_page_state(NR_SLAB_UNRECLAIMABLE) > nr_lru);
}