void hash_save_key(char *key, void *value, GSList **list)
{
        *list = g_slist_append(*list, strdup(key));
}

void free_key_value(gpointer data)
{
        g_free(data);
}