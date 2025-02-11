static void _d_rehash(struct dentry *entry)
{
    if (!entry) {
        return;
    }
    __d_rehash(entry, d_hash(entry->d_parent, entry->d_name.hash));
}