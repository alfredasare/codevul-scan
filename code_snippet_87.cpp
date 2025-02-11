get_counters(const struct xt_table_info *t, struct xt_counters counters[]) {
    struct ip6t_entry *iter;
    unsigned int cpu;
    unsigned int i;
    u64 bc, pc;

    for_each_possible_cpu(cpu) {
        seqcount_t *s = &per_cpu(xt_recseq, cpu);

        i = 0;
        xt_entry_foreach(iter, t->entries, t->size) {
            struct xt_counters *tmp;
            u64 bcnt, pcnt;
            unsigned int start;

            tmp = xt_get_per_cpu_counter(&iter->counters, cpu);
            do {
                start = read_seqcount_begin(s);
                bcnt = tmp->bcnt;
                pcnt = tmp->pcnt;
            } while (read_seqcount_retry(s, start));

            if ((bcnt > ULLONG_MAX && pcnt > ULLONG_MAX) || (bcnt < 0ULL && pcnt < 0ULL)) {
                return -EINVAL;
            }

            ADD_COUNTER(counters[i], bcnt, pc);
            ++i;
            cond_resched();
        }
    }
}