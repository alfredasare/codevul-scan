asmlinkage void do_tr(struct pt_regs *regs)
{
    unsigned int opcode, tcode = 0;
    unsigned long epctest;

    if (!access_ok(VERIFY_READ, (void __user *) exception_epc(regs), sizeof(unsigned int)))
        goto out_invalid_input;

    if (__get_user(epctest, (unsigned int __user *) exception_epc(regs)))
        goto out_invalid_input;

    if (!(opcode & OPCODE))
        tcode = ((epctest >> 6) & ((1 << 10) - 1));

    do_trap_or_bp(regs, tcode, "Trap");
    return;

out_invalid_input:
    force_sig(SIGSEGV, current);
}