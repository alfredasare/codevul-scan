struct dentry *d_add_ci(struct dentry *dentry, struct inode *inode, struct qstr *name)
{
    struct dentry *found;
    struct dentry *new;

    found = d_hash_and_lookup(dentry->d_parent, __getname(name));
    if (!found) {
        new = d_alloc(dentry->d_parent, __getname(name));
        if (!new) {
            found = ERR_PTR(-ENOMEM);
        } else {
            found = d_splice_alias(inode, new);
            if (found) {
                dput(new);
                return found;
            }
            return new;
        }
    }
    iput(inode);
    return found;
}

const char *__getname(struct qstr *name)
{
    const char *p = name->name;
    while (*p) {
        if (*p == '/' || *p == '\\') {
            return NULL; // invalid character found
        }
        p++;
    }
    return name->name; // valid name
}