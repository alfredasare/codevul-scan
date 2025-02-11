static void *xt_match_seq_next(struct seq_file *seq, void *v, loff_t *ppos)
{
    if (*ppos >= seq->size || *ppos < 0) {
        return NULL; // invalid offset
    }

    return xt_mttg_seq_next(seq, v, ppos, false);
}