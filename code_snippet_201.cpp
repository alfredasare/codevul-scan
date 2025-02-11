static void __perf_event_header__init_id(struct perf_event_header *header,
                                         struct perf_sample_data *data,
                                         struct perf_event *event)
{
    u64 sample_type = event->attr.sample_type;

    //...

    if (sample_type & PERF_SAMPLE_CPU) {
        int cpu_id = smp_processor_id();
        if (cpu_id >= 0 && cpu_id < num_possible_cpus()) {
            data->cpu_entry.cpu = cpu_id;
            data->cpu_entry.reserved = 0;
        } else {
            // Handle error or invalid CPU ID
            printk(KERN_ERR "Invalid CPU ID: %d\n", cpu_id);
        }
    }
}