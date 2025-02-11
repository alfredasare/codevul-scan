static int tg_cfs_schedulable_down(struct task_group *tg, void *data)
{
    struct cfs_schedulable_data *d = data;
    struct cfs_bandwidth *cfs_b = &tg->cfs_bandwidth;
    s64 quota = 0, parent_quota = -1;

    if (!tg->parent) {
        quota = RUNTIME_INF;
    } else {
        struct cfs_bandwidth *parent_b = &tg->parent->cfs_bandwidth;

        quota = normalize_cfs_quota(tg, d);
        parent_quota = parent_b->hierarchical_quota;

        // Validate the quota variable
        if (quota > INT64_MAX || quota < INT64_MIN) {
            return -EINVAL;
        }

        if (quota == RUNTIME_INF)
            quota = parent_quota;
        else if (parent_quota!= RUNTIME_INF && quota > parent_quota)
            return -EINVAL;
    }

    if (quota!= RUNTIME_INF && quota <= INT64_MAX) {
        cfs_b->hierarchical_quota = quota;
    } else {
        // Ensure max(child_quota) <= parent_quota, inherit when no limit is set
        cfs_b->hierarchical_quota = parent_quota;
    }

    return 0;
}