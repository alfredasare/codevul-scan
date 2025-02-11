free_all_not_allocator(clump_t *cp, void *arg)
{
    struct free_data *fd = (struct free_data *)arg;
    size_t min_size = cp->cbase + sizeof(obj_header_t);
    
    if (min_size > (size_t)fd->imem) {
        alloc_free_clump(cp, fd->imem);
    } else if (min_size == (size_t)fd->imem) {
        fd->allocator = cp;
    } else {
        // Handle error or unexpected cases
        // ...
    }

    return SPLAY_APP_CONTINUE;
}