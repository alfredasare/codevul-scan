static void dentry_lru_add(struct dentry *dentry)
{
    if (!dentry_on_dcache_lru(dentry)) {
        d_lru_add(dentry);
    }
}