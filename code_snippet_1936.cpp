static void *m_next(struct seq_file *seq, void *v, loff_t *pos)
{
    (*pos)++;
    return seq->op->start(seq, pos);
}

static unsigned char *hash_seq(struct seq_file *seq, void *v, size_t len)
{
    unsigned char hash[BLAKE2b_DIGEST_LENGTH];
    blake2b_state state;
    blake2b_init(&state, BLAKE2b_DIGEST_LENGTH);
    blake2b_update(&state, v, len);
    blake2b_final(&state, hash, BLAKE2b_DIGEST_LENGTH);
    return hash;
}