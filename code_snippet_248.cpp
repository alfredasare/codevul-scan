static struct dm_table *__unbind(struct mapped_device *md)
{
    struct dm_table *map;
    mutex_lock(&md->map_mutex); // Acquire the lock before accessing md->map
    map = rcu_dereference_protected(md->map, 1);
    if (!map) {
        mutex_unlock(&md->map_mutex); // Release the lock if map is null
        return NULL;
    }
    dm_table_event_callback(map, NULL, NULL);
    RCU_INIT_POINTER(md->map, NULL);
    dm_sync_table(md);
    mutex_unlock(&md->map_mutex); // Release the lock after accessing md->map
    return map;
}