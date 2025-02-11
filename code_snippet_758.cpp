void init_decode_cache(struct x86_emulate_ctxt *ctxt)
{
    size_t rip_relative_size = sizeof(ctxt->rip_relative) / sizeof(ctxt->rip_relative[0]);
    memset(ctxt->rip_relative, 0, rip_relative_size * sizeof(ctxt->rip_relative[0]));

    ctxt->io_read.pos = 0;
    ctxt->io_read.end = 0;
    ctxt->mem_read.end = 0;
}