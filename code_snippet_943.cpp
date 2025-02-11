get_offset_from_virtaddr(struct magic_set *ms, int swap, int clazz, int fd,
    off_t off, int num, off_t fsize, uint64_t virtaddr)
{
    Elf32_Phdr ph32;
    Elf64_Phdr ph64;

    for ( ; num; num--) {
        if (pread(fd, &ph32, sizeof(Elf32_Phdr), off) < sizeof(Elf32_Phdr)) {
            file_badread(ms);
            return -1;
        }
        off += sizeof(Elf32_Phdr);

        if (fsize!= SIZE_UNKNOWN && off > fsize) {
            /* Perhaps warn here */
            continue;
        }

        if (virtaddr >= ph32.p_vaddr && virtaddr < ph32.p_vaddr + ph32.p_filesz)
            return off + (virtaddr - ph32.p_vaddr);

        if (pread(fd, &ph64, sizeof(Elf64_Phdr), off) < sizeof(Elf64_Phdr)) {
            file_badread(ms);
            return -1;
        }
        off += sizeof(Elf64_Phdr);

        if (fsize!= SIZE_UNKNOWN && off > fsize) {
            /* Perhaps warn here */
            continue;
        }

        if (virtaddr >= ph64.p_vaddr && virtaddr < ph64.p_vaddr + ph64.p_filesz)
            return off + (virtaddr - ph64.p_vaddr);
    }
    return 0;
}