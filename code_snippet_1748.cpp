static void xfrm6_tunnel_destroy(struct xfrm_state *x)
{
	if (x && x->props.saddr.ss_family != AF_UNSPEC) {
		xfrm6_tunnel_free_spi(&x->props.saddr);
	}
}