static void xfrm6_tunnel_destroy(struct xfrm_state *x)
{
    uint32_t spi = x->props.saddr;
    xfrm6_tunnel_free_spi((uint32_t *)&spi);
}