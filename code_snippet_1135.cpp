static int br\_mdb\_copy(struct net\_bridge\_mdb\_htable \*new,
 struct net\_bridge\_mdb\_htable \*old,
 int elasticity)
{
 struct net\_bridge\_mdb\_entry \*mp;
 struct hlist\_node \*p;
 int maxlen = 0;
 int len;
 int i;

 for (i = 0; i < old->max; i++)
 hlist\_for\_each\_entry(mp, p, &old->mhash[i], hlist[old->ver])
 hlist\_add\_head(&mp->hlist[new->ver],
 &new->mhash[br\_ip\_hash(new, &mp->addr)]);

 if (!elasticity)
 return 0;

 for (i = 0; i < new->max; i++) {
 len = 0;
 hlist\_for\_each\_entry(mp, p, &new->mhash[i], hlist[new->ver])
 len++;

 if (len > maxlen)
 maxlen = len;
 }

 return maxlen > elasticity ? -EINVAL : 0;
}