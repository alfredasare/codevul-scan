static int sit\_tunnel\_rcv(struct sk\_buff \*skb, u8 ipproto)
{
const struct iphdr \*iph;
struct ip\_tunnel \*tunnel;
int sifindex;
struct net \*net = dev\_net(skb->dev);

rtnl\_lock();

sifindex = netif\_is\_l3\_master(skb->dev) ? IPCB(skb)->iif : 0;

iph = ip\_hdr(skb);
tunnel = ipip6\_tunnel\_lookup(net, skb->dev,
iph->saddr, iph->daddr, sifindex);
if (tunnel) {
const struct tnl\_ptk\_info \*tpi;

if (tunnel->parms.iph.protocol != ipproto &&
tunnel->parms.iph.protocol != 0)
goto drop;

if (!xfrm4\_policy\_check(NULL, XFRM\_POLICY\_IN, skb))
goto drop;
#if IS\_ENABLED(CONFIG\_MPLS)
if (ipproto == IPPROTO\_MPLS)
tpi = &mplsip\_tpi;
else
#endif
tpi = &ipip\_tpi;
if (iptunnel\_pull\_header(skb, 0, tpi->proto, false))
goto drop;
return ip\_tunnel\_rcv(tunnel, skb, tpi, NULL, log\_ecn\_error);
}

rtnl\_unlock();

return 1;

drop:
kfree\_skb(skb);
rtnl\_unlock();
return 0;
}