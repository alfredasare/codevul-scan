static ssize_t o2nm_node_ipv4_address_show(struct config_item *item, char *page)
{
    size_t page_len = PAGE_SIZE - 1; // Leave room for null-terminator
    const struct o2nm_node *node = to_o2nm_node(item);

    if (snprintf(page, page_len, "%pI4\n", &node->nd_ipv4_address) >= page_len) {
        return -ENOMEM;
    }

    return strlen(page);
}