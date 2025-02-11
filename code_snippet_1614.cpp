#include <linux/spinlock.h>

DEFINE_SPINLOCK(ip_flush_lock);

void ip_flush_pending_frames(struct sock *sk)
{
	spin_lock(&ip_flush_lock);
	__ip_flush_pending_frames(sk, &sk->sk_write_queue, &inet_sk(sk)->cork.base);
	spin_unlock(&ip_flush_lock);
}