void cl_block(GifCtx *ctx) {
    cl_hash((count_int)hsize, ctx);
    ctx->free_ent = ctx->ClearCode;
    free(ctx->ClearCode);
    ctx->ClearCode = NULL;
    ctx->clear_flg = 1;

    output((code_int)ctx->ClearCode, ctx);
}