static int etm_event_validate(struct perf_event *event) {
    if (!event || event->size < sizeof(struct perf_event)) {
        return -EINVAL;
    }
    return 0;
}

static void etm_event_read(struct perf_event *event) {
    int ret = etm_event_validate(event);
    if (ret) {
        printk(KERN_ERR "Invalid perf_event struct\n");
        return;
    }
    // Process the validated event struct
}