ofport_equal(const struct ofputil_phy_port *a,
             const struct ofputil_phy_port *b)
{
    return (memcmp(a->hw_addr, b->hw_addr, ETH_ADDR_SIZE) == 0
            && a->state == b->state
            &&!((a->config ^ b->config) & OFPUTIL_PC_PORT_DOWN)
            && a->curr == b->curr
            && a->advertised == b->advertised
            && a->supported == b->supported
            && a->peer == b->peer
            && a->curr_speed == b->curr_speed
            && a->max_speed == b->max_speed);
}