static __init int init_posix_timers(void)
{
    size_t size = sizeof(struct k_itimer); // Define a constant size
    posix_timers_cache = kmem_cache_create("posix_timers_cache", size, 0, SLAB_PANIC, NULL);
    return 0;
}