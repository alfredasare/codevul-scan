static inline struct sk_buff *pfkey_xfrm_state2msg_expire(const struct xfrm_state *x, size_t hsc)
{
    if (hsc > SIZE_MAX / sizeof(*x)) {
        return NULL; // or handle the error as needed
    }
    return __pfkey_xfrm_state2msg(x, 0, (size_t)hsc);
}