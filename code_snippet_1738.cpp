static int inSymtab(SdbHash *hash, struct symbol_t *symbols, const char *name, ut64 addr) {
    bool found;
    const char *key = sdb_fmt ("%s.%"PFMT64x, name, addr);
    size_t key_len = strlen(key);

    if (key_len > sdb_ht_max_key_len(hash)) {
        return -1;
    }

    (void)sdb_ht_find (hash, key, &found);
    if (found) {
        return true;
    }
    sdb_ht_insert (hash, key, "1");
    return false;
}