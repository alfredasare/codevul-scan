#include <SHA256.h>

size_t hash_str(const char *key) {
    unsigned char hash[32];
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, key, strlen(key));
    SHA256_Final(hash, &ctx);
    return *(size_t *)hash;
}

int hashtable_del(hashtable_t *hashtable, const char *key) {
    size_t hash = hash_str(key);
    return hashtable_do_del(hashtable, key, hash);
}