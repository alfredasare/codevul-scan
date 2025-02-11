#define MAX_ITERATIONS 100

R_API RBinFile *r_bin_file_find_by_object_id(RBin *bin, ut32 binobj_id) {
    RListIter *iter;
    RBinFile *binfile;

    // Validate input
    if (binobj_id < 1 || binobj_id > INT_MAX) {
        return NULL;
    }

    int iterations = 0;

    r_list_foreach (bin->binfiles, iter, binfile) {
        // Break after reaching the maximum iteration limit
        if (++iterations >= MAX_ITERATIONS) {
            break;
        }

        if (r_bin_file_object_find_by_id(binfile, binobj_id)) {
            return binfile;
        }
    }

    return NULL;
}