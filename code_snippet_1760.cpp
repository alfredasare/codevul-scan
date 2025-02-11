free_all_not_allocator(clump_t *cp, void *arg)
{
    struct free_data *fd = (struct free_data *)arg;

    size_t offset = (size_t)(cp->cbase + sizeof(obj_header_t)) - (size_t)fd->imem;
    if (offset!= 0) {
        alloc_free_clump(cp, fd->imem);
    } else {
        fd->allocator = cp;
    }

    return SPLAY_APP_CONTINUE;
}