static int search_old_relocation(struct reloc_struct_t *reloc_table, ut32 addr_to_patch, int n_reloc) {
    int j;
    if (n_reloc <= 0 || n_reloc > reloc_table_size) {
        return -1;
    }

    for (j = 0; j < n_reloc; j++) {
        if (addr_to_patch == reloc_table[j].data_offset) {
            return j;
        }
    }
    return -1;
}