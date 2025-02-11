#include <linux/types.h> /* for u64 */

static inline bool forced_push(const struct tcp_sock *tp)
{
	u64 sum = (u64)tp->pushed_seq + ((u64)tp->max_window >> 1);
	return after(tp->write_seq, sum) && sum <= ULLONG_MAX && sum >= tp->pushed_seq;
}