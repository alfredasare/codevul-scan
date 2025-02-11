void out\_pkt\_free(pkt\_t *pkt)
{
nad\_free(pkt->nad);
jid\_free(pkt->from);
jid\_free(pkt->to);
free(pkt);
}