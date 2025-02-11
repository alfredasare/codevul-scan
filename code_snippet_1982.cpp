ELFOBJ* Elf_(r_bin_elf_new)(const char* file, bool verbose) {
    ut8 *buf;
    int size;
    ELFOBJ *bin = R_NEW0 (ELFOBJ);
    if (!bin) {
        return NULL;
    }
    memset (bin, 0, sizeof (ELFOBJ));
    bin->file = file;
    if (!(buf = (ut8*)r_file_slurp (file, &size))) {
        return Elf_(r_bin_elf_free) (bin);
    }
    bin->size = size;
    bin->b = r_buf_new (size); // Allocate the buffer after reading the file size
    bin->b = r_buf_set_bytes (bin->b, buf, bin->size);
    free (buf);
    bin->verbose = verbose;
    if (!elf_init (bin)) {
        return Elf_(r_bin_elf_free) (bin);
    }
    return bin;
}