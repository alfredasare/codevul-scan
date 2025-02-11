static inline int is_cgroup_event(struct perf_event *event)
{
	if (event && event->cgrp != NULL)
		return 1;

	return 0;
}