#define MAX_SLUB_DEBUG_SLABS_LEN 64

static unsigned long kmem_cache_flags(unsigned long objsize,
	unsigned long flags, const char *name,
	void (*ctor)(struct kmem_cache *, void *))
{
	char slub_debug_slabs_limited[MAX_SLUB_DEBUG_SLABS_LEN];

	/*
	 * Enable debugging if selected on the kernel commandline.
	 */
	if (slub_debug && (!slub_debug_slabs ||
	    strncmp(slub_debug_slabs_limited, name, strnlen(slub_debug_slabs, MAX_SLUB_DEBUG_SLABS_LEN)) == 0))
		flags |= slub_debug;

	return flags;
}