void __init taskstats_init_early(void)
{
    unsigned int i;
    char *format_string = "%d"; // Safe format string

    taskstats_cache = KMEM_CACHE(taskstats, SLAB_PANIC);
    for_each_possible_cpu(i) {
        INIT_LIST_HEAD(&(per_cpu(listener_array, i).list));
        rwsem_init(&(per_cpu(listener_array, i).sem), format_string);
    }
}