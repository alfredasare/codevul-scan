static int em_fnstsw(struct x86_emulate_ctxt *ctxt)
{
	u16 fsw;

	if (ctxt->ops->get_cr(ctxt, 0) & (X86_CR0_TS | X86_CR0_EM))
		return emulate_nm(ctxt);

	ctxt->ops->get_fpu(ctxt);
	asm volatile("fnstsw %0": "+m"(fsw));

	if (fsw & 0x0400) {
		ctxt->ops->put_fpu(ctxt);
		return emulate_exception(ctxt, X86_EM_EX_INTERRUPT, 1);
	}

	ctxt->dst.val = fsw;
	ctxt->ops->put_fpu(ctxt);

	return X86EMUL_CONTINUE;
}