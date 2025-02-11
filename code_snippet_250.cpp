static struct dm_table *__unbind(struct mapped_device *md)
{
	struct dm_table *map = rcu_dereference_protected(md->map, 2);

	if (!map)
		return NULL;

	dm_table_event_callback(map, NULL, NULL);
	synchronize_rcu();
	RCU_INIT_POINTER(md->map, NULL);

	return map;
}