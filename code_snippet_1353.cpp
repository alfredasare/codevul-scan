static int collect_events(struct perf_event *group, int max_count,
			  struct perf_event *ctrs[], u64 *events,
			  unsigned int *flags)
{
	int n = -1;
	struct perf_event *event;

	if (!is_software_event(group)) {
		if (n >= 0 && n < max_count) {
			ctrs[n] = group;
			flags[n] = group->hw.event_base;
			events[n++] = group->hw.config;
		} else {
			return -1;
		}
	}
	list_for_each_entry(event, &group->sibling_list, group_entry) {
		if (!is_software_event(event) && event->state!= PERF_EVENT_STATE_OFF) {
			if (n >= 0 && n < max_count) {
				ctrs[n] = event;
				flags[n] = event->hw.event_base;
				events[n++] = event->hw.config;
			} else {
				return -1;
			}
		}
	}
	return n;
}