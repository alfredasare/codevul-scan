static int inSymtab(SdbHash *hash, struct symbol_t *symbols, const char *name, ut64 addr) {
	bool found;
	char key[SDB_KEY_MAX]; // Allocate a safe buffer for the key
	sdb_snprintf(key, sizeof(key), "%s.%" PFMT64x, name, addr); // Use sdb_snprintf with a safe buffer size
	(void)sdb_ht_find(hash, key, &found);
	if (found) {
		return true;
	}
	sdb_ht_insert(hash, key, "1");
	return false;
}