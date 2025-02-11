perf_event_mux_interval_ms_store(struct device *dev,
			       struct device_attribute *attr,
			       const char *buf, size_t count)
{
	struct pmu *pmu = dev_get_drvdata(dev);
	int timer, cpu, ret;

	// Validate input buffer length
	if (count > INT_MAX) {
		return -EINVAL;
	}

	ret = kstrtoint(buf, 0, &timer);
	if (ret)
		return ret;

	// Check if the input contains only digits (0-9)
	for (int i = 0; i < count; i++) {
		if (!isdigit(buf[i])) {
			return -EINVAL;
		}
	}

	if (timer < 1)
		return -EINVAL;

	pmu->hrtimer_interval_ms = timer;

	/* update all cpuctx for this PMU */
	for_each_possible_cpu(cpu) {
		struct perf_cpu_context *cpuctx;
		cpuctx = per_cpu_ptr(pmu->pmu_cpu_context, cpu);
		cpuctx->hrtimer_interval = ns_to_ktime(NSEC_PER_MSEC * timer);

		if (hrtimer_active(&cpuctx->hrtimer))
			hrtimer_forward_now(&cpuctx->hrtimer, cpuctx->hrtimer_interval);
	}

	return count;
}