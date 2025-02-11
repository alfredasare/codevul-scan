static int emulate_nm_fixed(struct x86_emulate_ctxt *ctxt, int vector, int error_code, bool in_kernel_mode)
{
    return emulate_exception(ctxt, vector, error_code, in_kernel_mode, /* Additional arguments if necessary */);
}