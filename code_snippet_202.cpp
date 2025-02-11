static void __perf_event_header__init_id(struct perf_event_header *header,
					 struct perf_sample_data *data,
					 struct perf_event *event)
{
	u64 sample_type = event->attr.sample_type;
	size_t required_size = 0;

	data->type = sample_type;
	header->size += event->id_header_size;

	if (sample_type & PERF_SAMPLE_TID) {
		/* namespace issues */
		data->tid_entry.pid = perf_event_pid(event, current);
		data->tid_entry.tid = perf_event_tid(event, current);
		required_size = sizeof(data->tid_entry);
		if (header->size < required_size)
			header->size = required_size;
	}

	if (sample_type & PERF_SAMPLE_TIME) {
		data->time = perf_event_clock(event);
		required_size = sizeof(data->time);
		if (header->size < required_size)
			header->size = required_size;
	}

	if (sample_type & (PERF_SAMPLE_ID | PERF_SAMPLE_IDENTIFIER)) {
		data->id = primary_event_id(event);
		required_size = sizeof(data->id);
		if (header->size < required_size)
			header->size = required_size;
	}

	if (sample_type & PERF_SAMPLE_STREAM_ID) {
		data->stream_id = event->id;
		required_size = sizeof(data->stream_id);
		if (header->size < required_size)
			header->size = required_size;
	}

	if (sample_type & PERF_SAMPLE_CPU) {
		data->cpu_entry.cpu	 = raw_smp_processor_id();
		data->cpu_entry.reserved = 0;
		required_size = sizeof(data->cpu_entry);
		if (header->size < required_size)
			header->size = required_size;
	}
}