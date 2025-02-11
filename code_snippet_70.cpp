static inline struct sk_buff *pfkey_xfrm_state2msg_expire(const struct xfrm_state *x, int hsc)
{
	struct sk_buff *msg = __pfkey_xfrm_state2msg(x, 0, hsc);
	return msg ?: NULL;
}