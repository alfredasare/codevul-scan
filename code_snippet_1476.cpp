void* r_bin_dyldcache_free(struct r_bin_dyldcache_obj_t* bin) {
    if (!bin) {
        return NULL;
    }
    if (bin->b) {
        free(bin->b);
    }
    if (bin) {
        free(bin);
    }
    return NULL;
}