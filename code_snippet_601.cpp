static struct pmu *perf_init_event(struct perf_event *event)
{
	struct pmu *pmu = NULL;
	int idx;
	int ret;

	idx = srcu_read_lock(&pmus_srcu);

	rcu_read_lock();
	pmu = idr_find(&pmu_idr, event->attr.type);
	rcu_read_unlock();
	if (pmu) {
		ret = perf_try_init_event(pmu, event);
		if (ret) {
			pmu = ERR_PTR(ret);
			goto unlock;
		}
	} else {
		list_for_each_entry_rcu(pmu, &pmus, entry) {
			ret = perf_try_init_event(pmu, event);
			if (!ret)
				break;

			if (ret != -ENOENT) {
				pmu = ERR_PTR(ret);
				goto unlock;
			}
		}
		if (ret == -ENOENT)
			pmu = ERR_PTR(-ENOENT);
	}
unlock:
	srcu_read_unlock(&pmus_srcu, idx);
	rcu_read_unlock();

	return pmu;
}