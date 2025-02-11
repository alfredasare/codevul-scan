static void ksm_do_scan(unsigned int scan_npages)
{
    struct rmap_item *rmap_item;
    struct page *page;

    while (scan_npages-- && likely(!freezing(current))) {
        cond_resched();
        rmap_item = scan_get_next_rmap_item(&page);
        if (!rmap_item)
            return;
        if (!is_ksm_page(page) ||!is_stable_tree(rmap_item))
            cmp_and_merge_page(page, rmap_item);
        put_page(page);
    }
}