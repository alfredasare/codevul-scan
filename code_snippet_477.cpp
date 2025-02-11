void user_describe(const struct key *key, struct seq_file *m)
{
    size_t desc_len = strlen(key->description);
    seq_puts_n(m, key->description, desc_len);
    if (key_is_instantiated(key))
        seq_printf(m, ": %u", key->datalen);
}