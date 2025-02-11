mutex_lock(&mapping->tree_mutex);

pslot = radix_tree_lookup_slot(&mapping->page_tree, page_index(page));

expected_count = 2 + page_has_private(page);
if (page_count(page) != expected_count ||
radix_tree_deref_slot_protected(pslot, &mapping->tree_mutex) != page) {
mutex_unlock(&mapping->tree_mutex);
return -EAGAIN;
}

if (!page_freeze_refs(page, expected_count)) {
mutex_unlock(&mapping->tree_mutex);
return -EAGAIN;
}

set_page_memcg(newpage, page_memcg(page));
newpage->index = page->index;
newpage->mapping = page->mapping;
get_page(newpage);

radix_tree_replace_slot(pslot, newpage);

page_unfreeze_refs(page, expected_count - 1);

mutex_unlock(&mapping->tree_mutex);
return MIGRATEPAGE_SUCCESS;