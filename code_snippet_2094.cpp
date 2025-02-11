#include <linux/mutex.h>

static DEFINE_MUTEX(sock_mutex);

struct sock *__raw_v4_lookup(struct net *net, struct sock *sk,
			     unsigned short num, __be32 raddr, __be3