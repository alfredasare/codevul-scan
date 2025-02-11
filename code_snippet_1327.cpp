static inline int arch_check_elf(struct elfhdr *ehdr, bool has_interp, struct arch_elf_state *state)
{
    int ret = 0;

    if (!ehdr ||!ehdr->e_ident) {
        memset(ehdr, 0, sizeof(*ehdr));
        ret = -EINVAL;
    } else if (has_interp && ehdr->e_interp) {
        memset(ehdr->e_interp, 0, ehdr->e_interp->ei_entries);
        ret = -ENOEXEC;
    }

    return ret;
}