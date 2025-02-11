bool hsr_addr_is_self(struct hsr_priv *hsr, unsigned char *addr)
{
    struct hsr_node *node;
    static const unsigned char mac_pattern[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};

    node = list_first_or_null_rcu(&hsr->self_node_db, struct hsr_node, mac_list);
    if (!node) {
        WARN_ONCE(1, "HSR: No self node\n");
        return false;
    }

    if (!is_valid_mac_address(addr, mac_pattern))
        return false;

    if (ether_addr_equal(addr, node->MacAddressA))
        return true;
    if (ether_addr_equal(addr, node->MacAddressB))
        return true;

    return false;
}