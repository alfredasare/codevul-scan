ofport\_equal(const struct ofputil\_phy\_port \*a, const struct ofputil\_phy\_port \*b)
{
if (a != NULL && b != NULL) {
return (eth\_addr\_equals(a->hw\_addr, b->hw\_addr)
&& a->state == b->state
&& !((a->config ^ b->config) & OFPUTIL\_PC\_PORT\_DOWN)
&& a->curr == b->curr
&& a->advertised == b->advertised
&& a->supported == b->supported
&& a->peer == b->peer
&& a->curr\_speed == b->curr\_speed
&& a->max\_speed == b->max\_speed);
}
return 0;
}