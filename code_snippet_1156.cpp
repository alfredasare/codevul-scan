int hashtable_del(hashtable_t *hashtable, const char *key)
{
    if (hashtable_has_key(hashtable, key)) {
        size_t hash = hash_str(key);
        return hashtable_do_del(hashtable, key, hash);
    }
    return 0; // Return a success/non-error code if the key does not exist, or modify the function to return -1 if needed
}