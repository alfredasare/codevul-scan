static int inSymtab(SdbHash *hash, struct symbol_t *symbols, const char *name, ut64 addr) {
	bool found;
	const char *key = sdb_fmt (0, "%s.%"PFMT64x, name, addr);
	if (!sdb_ht_find (hash, key, &found) && !found) {
		sdb_ht_insert (hash, key, "1");
	} else {
		free((void*)key);
	}
	if (found) {
		return true;
	}
	return false;
}