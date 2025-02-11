static bool mnt_ns_loop(struct dentry *dentry)
{
    struct mnt_namespace *mnt_ns;

    if (!is_mnt_ns_file(dentry)) {
        return false;
    }

    dentry = sanitize_dentry(dentry);

    mnt_ns = get_proc_ns(dentry->d_inode)->ns;
    return current->nsproxy->mnt_ns->seq >= mnt_ns->seq;
}

struct dentry *sanitize_dentry(struct dentry *dentry)
{
    if (!dentry) {
        return NULL;
    }

    // Validate and sanitize dentry object
    //...

    return dentry;
}