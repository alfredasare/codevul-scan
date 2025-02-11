R_API RBinFile *r_bin_file_find_by_object_id(RBin *bin, ut32 binobj_id) {
    RListIter *iter;
    RBinFile *binfile;
    r_list_iter_get_safe(bin->binfiles, iter) {
        binfile = r_list_iter_get_value(iter);
        if (r_bin_file_object_find_by_id(binfile, binobj_id)) {
            return binfile;
        }
    }
    return NULL;
}