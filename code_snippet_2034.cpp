static int elf_idx(struct user_ta_ctx *utc, vaddr_t r_va, size_t r_size)
{
    struct user_ta_elf *elf;
    size_t idx = 0;

    TAILQ_FOREACH(elf, &utc->elfs, link) {
        size_t n;

        for (n = 0; n < elf->num_segs; n++)
            if (elf->segs[n].va == r_va && elf->segs[n].size == r_size)
                return (int)idx;
        idx++;
    }
    return -1;
}