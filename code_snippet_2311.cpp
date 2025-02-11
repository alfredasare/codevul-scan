int sk\_filter(struct sock \*sk, struct sk\_buff \*skb)
{
	int err;
	struct sk\_filter \*filter;

	/*
	 * If the skb was allocated from pfmemalloc reserves, only
	 * allow SOCK\_MEMALLOC sockets to use it as this socket is
	 * helping free memory