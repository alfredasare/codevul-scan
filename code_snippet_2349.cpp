static int show_tid_numa_map(struct seq_file *m, void *v)
{
    if (!m ||!v) {
        seq_printf(m, "Error: Invalid input\n");
        return -EINVAL;
    }

    return show_numa_map(m, v, 0);
}