code:


void hash_save_key(char *key, void *value, GSList **list)
{
    GSList *local_list = *list;
    *list = g_slist_append(local_list, key);
}