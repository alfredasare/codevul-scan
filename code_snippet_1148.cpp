static void perf_free_event(struct perf_event *event,
			    struct perf_event_context *ctx)
{
	struct perf_event *parent = event->parent;

	if (!parent || !parent->per_cpu || !parent->per_cpu[smp_processor_id()])
		return;

	mutex_lock(&parent->child_mutex);
	list_del_init(&event->child_list);
	mutex_unlock(&parent->child_mutex);

	put_event(parent);

	perf_group_detach(event);
	list_del_event(event, ctx);
	free_event(event);
}