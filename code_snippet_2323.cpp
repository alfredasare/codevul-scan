static __init int init_posix_timers(void)
{
	posix_timers_cache = kmem_cache_create("posix_timers_cache",
					sizeof (struct k_itimer), sizeof(size_t), SLAB_PANIC,