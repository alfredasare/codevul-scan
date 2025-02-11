static void lrw_aesni_exit_tfm(struct crypto_tfm *tfm)
{
    struct aesni_lrw_ctx *ctx = crypto_tfm_ctx(tfm);
    if (ctx->lrw_table) {
        lrw_free_table(&ctx->lrw_table);
        ctx->lrw_table = NULL;
    }
}