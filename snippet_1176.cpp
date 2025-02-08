static inline unsigned char swap_count(unsigned char ent)
{
	return ent & ~SWAP_HAS_CACHE;	/* may include SWAP_HAS_CONT flag */
}
