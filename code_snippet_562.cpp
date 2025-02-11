#include "sched.h"

#define MAX_ENTITIES 100

void dequeue_load_avg(struct cfs_rq *cfs_rq, struct sched_entity *se) {
    if (cfs_rq == NULL || se == NULL) {
        printk("Error: Invalid input entity\n");
        return;
    }

    if (cfs_rq->nr_running >= MAX_ENTITIES || se->avg.load_sum < 0) {
        printk("Error: Exceeded maximum entities or invalid load sum\n");
        return;
    }

    se->avg.load_sum -= cfs_rq->avg_decay_log;
}