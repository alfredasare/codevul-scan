static int f2fs_write_node_page(struct page *page,
			     struct writeback_control *wbc)
{
    if (!is_valid_page(page)) {
        return -EINVAL;
    }
    if (!is_valid_writeback_control(wbc)) {
        return -EINVAL;
    }
    return __write_node_page(page, false, NULL, wbc);
}