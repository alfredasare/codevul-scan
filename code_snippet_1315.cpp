#define MAX\_SIZE (INT\_MAX - 100)

static int inet\_netconf\_msgsize\_devconf(int type)
{
 int size = NLMSG\_ALIGN(sizeof(struct netconfmsg))
 + nla\_total\_size(4); \*\*/* NETCONFA\_IFINDEX \]*
 bool all = false;

if (type == NETCONFA\_ALL)
all = true;

if (all || type == NETCONFA\_FORWARDING)
size += nla\_total\_size(4);
if (all || type == NETCONFA\_RP\_FILTER)
size += nla\_total\_size(4);
if (all || type == NETCONFA\_MC\_FORWARDING)
size += nla\_total\_size(4);
if (all || type == NETCONFA\_PROXY\_NEIGH)
size += nla\_total\_size(4);
if (all || type == NETCONFA\_IGNORE\_ROUTES\_WITH\_LINKDOWN)
size += nla\_total\_size(4);

if (size > MAX\_SIZE) {
// Handle error condition
return -1;
}

return size;
}