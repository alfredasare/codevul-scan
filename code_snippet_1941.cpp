static int rtnl\_net\_dumpid\_one(int id, void \*peer, void \*data)
{
struct rtnl\_net\_dump\_cb \*net\_cb = (struct rtnl\_net\_dump\_cb \*)data;
int ret;

if (net\_cb->idx < net\_cb->s\_idx)
goto cont;

net\_cb->fillargs.nsid = id;
if (net\_cb->fillargs.add\_ref)
net\_cb->fillargs.ref\_nsid = \_\_peernet2id(net\_cb->ref\_net, peer);
ret = rtnl\_net\_fill(net\_cb->skb, &net\_cb->fillargs);
if (ret < 0)
return ret;

cont:
net\_cb->idx++;
if (ret >= 0)
return 0;
}