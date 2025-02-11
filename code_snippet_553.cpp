void post_init_entity_util_avg(struct sched_entity *se)
{
    struct cfs_rq *cfs_rq = cfs_rq_of(se);
    struct sched_avg *sa = &se->avg;
    long cpu_scale = 0; // Initialize cpu_scale to a safe value
    const long MAX_CPU_SCALE = 1000; // Define a secure and well-defined constant

    // Validate input to cpu_scale
    if (cpu_scale < 0 || cpu_scale > MAX_CPU_SCALE) {
        // Handle error or reject invalid input
        return;
    }

    long cap = (long)(cpu_scale - cfs_rq->avg.util_avg) / 2;

    if (cap > 0) {
        if (cfs_rq->avg.util_avg!= 0) {
            sa->util_avg  = cfs_rq->avg.util_avg * se->load.weight;
            sa->util_avg /= (cfs_rq->avg.load_avg + 1);

            if (sa->util_avg > cap)
                sa->util_avg = cap;
        } else {
            sa->util_avg = cap;
        }
    }

    if (entity_is_task(se)) {
        struct task_struct *p = task_of(se);
        if (p->sched_class!= &fair_sched_class) {
            /*... */
        }
    }

    attach_entity_cfs_rq(se);
}