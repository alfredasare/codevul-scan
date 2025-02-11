u64 ring_buffer_time_stamp(struct ring_buffer *buffer, int cpu)
{
	u64 time;
	int error;

	preempt_disable_notrace();
	error = rb_time_stamp(buffer);
	if (!error) {
		preempt_enable_no_resched_notrace();
		return time;
	}
	preempt_enable_notrace();
	return 0; /* or an appropriate error value */
}