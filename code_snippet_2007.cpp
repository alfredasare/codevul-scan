unsigned long __user *nm = NULL;
unsigned long nr_bits, alloc_size;
nodemask_t bm;
int bits_matched;

nr_bits = min_t(unsigned long, maxnode-1, MAX_NUMNODES);
alloc_size = ALIGN(nr_bits, BITS_PER_LONG) / 8;

if (nmask) {
	bits_matched = compat_get_bitmap(nodes_addr(bm), nmask, nr_bits);
	if (bits_matched != nr_bits)
		return -EINVAL;
	nm = compat_alloc_user_space(alloc_size);
	err |= copy_to_user(nm, nodes_addr(bm), alloc_size);
}

if (err)
	return -EFAULT;
return sys_mbind(start, len, mode, nm, nr_bits+1, flags);