static void commit_tree(struct mount *mnt, struct mount *shadows)
{
    struct mount *parent = mnt->mnt_parent;
    struct mount *m;
    LIST_HEAD(head);
    struct mnt_namespace *n = parent->mnt_ns;
    int i = 0;

    BUG_ON(parent == mnt);

    list_add_tail(&head, &mnt->mnt_list);

    list_for_each_entry(m, &head, mnt_list) {
        if (i >= 1024) {
            break;
        }
        m->mnt_ns = n;
        i++;
    }

    list_splice(&head, n->list.prev);

    attach_shadowed(mnt, parent, shadows);
    touch_mnt_namespace(n);
}