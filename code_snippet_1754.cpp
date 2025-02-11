rtadv_prefix_get (struct list *rplist, struct prefix_ipv6 *p)
{
  struct rtadv_prefix *rprefix;
  
  rprefix = rtadv_prefix_lookup (rplist, p);
  if (rprefix)
    return rprefix;

  rprefix = rtadv_prefix_new (p);
  listnode_add (rplist, rprefix);

  return rprefix;
}

rtadv_prefix_new (struct prefix_ipv6 *p)
{
  struct rtadv_prefix *rprefix;
  uint8_t buffer[sizeof(struct prefix_ipv6)];

  rprefix = malloc (sizeof (struct rtadv_prefix));
  memset (rprefix, 0, sizeof (struct rtadv_prefix));

  memcpy (buffer, p, sizeof(struct prefix_ipv6));
  memcpy (&rprefix->prefix, buffer, sizeof(struct prefix_ipv6));

  return rprefix;
}