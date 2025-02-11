#define MAX_CPUS num_possible_cpus()

int sched_group_set_shares(struct task_group *tg, unsigned long shares)
{
    int i;

    //... (rest of the function remains the same)

    for (i = 0; i < MAX_CPUS; i++) {
        struct rq *rq = cpu_rq(i);
        struct sched_entity *se = tg->se[i];
        struct rq_flags rf;

        //... (rest of the loop remains the same)
    }

    //...
}