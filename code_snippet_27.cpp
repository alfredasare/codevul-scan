static inline int is_cgroup_event(struct perf_event *event)
{
    if (!event ||!event->cgrp) {
        return 0;
    }

    if (strnlen(event->cgrp, CGRP_NAME_MAX) >= CGRP_NAME_MAX) {
        return 0;
    }

    return event->cgrp!= NULL;
}