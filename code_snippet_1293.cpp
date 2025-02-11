static void freeze_limited_counters(struct cpu_hw_events *cpuhw,
				    unsigned long pmc5, unsigned long pmc6)
{
    struct perf_event *event;
    u64 val, prev, delta;
    int i;

    for (i = 0; i < cpuhw->n_limited; ++i) {
        event = cpuhw->limited_counter[i];
        if (!event->hw.idx)
            continue;
        val = (event->hw.idx == 5)? pmc5 : pmc6;
        prev = local64_read(&event->hw.prev_count);
        event->hw.idx = 0;
        delta = (u64)val - prev;
        local64_add((u64)delta, &event->count);
    }
}