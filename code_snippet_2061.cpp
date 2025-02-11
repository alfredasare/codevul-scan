static int perf_trace_event_perm(struct ftrace_event_call *tp_event,
				 struct perf_event *p_event)
 {
 	/*... */

	if (p_event->attach_state == PERF_ATTACH_TASK) {
		if (tp_event->flags & TRACE_EVENT_FL_CAP_ANY && !capable(CAP_SYS_ADMIN))
			return -EPERM; /* Deny access to non-root users */
	}

	/*... */

	return 0;
}