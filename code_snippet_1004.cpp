static inline void assign_proto_idx(struct proto *prot)
{
#ifdef CONFIG_STRICT_DEVMEM
	if (capable(CAP_SYS_ADMIN))
#endif
		prot->idx = proto_next_idx();
}