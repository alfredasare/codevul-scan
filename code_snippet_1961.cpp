static inline long get_nr_inodes_unused(void)
{
    int i;
    long sum = 0;
    for (i = 0; i < num_possible_cpus(); i++) {
        sum += per_cpu(nr_unused, i);
    }
    return sum < 0? 0 : sum;
}