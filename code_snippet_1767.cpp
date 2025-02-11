static int em_fxrstor(struct x86_emulate_ctxt *ctxt)
{
    struct fxregs_state fx_state;
    int rc;

    //...

    if (rc == X86EMUL_CONTINUE) {
        struct fxregs_state *fx_state_ptr = &fx_state;
        rc = asm_safe("fxrstor %[fx]", : [fx] "r" (*fx_state_ptr));
    }

    //...
}