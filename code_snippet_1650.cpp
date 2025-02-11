static int get_eff_addr_modrm(struct insn *insn, struct pt_regs *regs, int *regoff, long *eff_addr) {
    long tmp;

    //... (rest of the code remains the same)

    if (*regoff == -EDOM) {
        if (user_64bit_mode(regs))
            tmp = regs->ip + insn->length;
        else
            tmp = 0;
    } else if (*regoff < 0) {
        return -EINVAL;
    } else {
        tmp = regs_get_register(regs, *regoff);
    }

    // Use a secure method to construct the format string
    char fmt_string[32];
    snprintf(fmt_string, sizeof(fmt_string), "%ld", tmp);

    if (insn->addr_bytes == 4) {
        int addr32 = (int)(tmp & 0xffffffff) + insn->displacement.value;

        *eff_addr = addr32 & 0xffffffff;
    } else {
        *eff_addr = tmp + insn->displacement.value;
    }

    return 0;
}