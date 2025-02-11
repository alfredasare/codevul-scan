static int inSymtab(SdbHash *hash, struct symbol_t *symbols, const char *name, ut64 addr) {
    bool found;
    const char *key = sdb_fmt(0, "%s.%"PFMT64x, name, addr);
    (void)sdb_ht_find(hash, key, &found);
    if (found) {
        return true;
    }

    // Upgrade to a secure hash function
    char hash_value[65]; // Assuming SHA-256 output is 64 characters + null terminator
    uint8_t hash_data[32]; // SHA-256 output size
    hash_data[0] = 0; // Initialize hash data
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, key, strlen(key));
    SHA256_Final(hash_data, &sha256);
    for (int i = 0; i < 32; i++) {
        sprintf(&hash_value[i * 2], "%02x", hash_data[i]);
    }
    hash_value[64] = '\0'; // Null terminate the hash value
    sdb_ht_insert(hash, hash_value, "1");
    return false;
}