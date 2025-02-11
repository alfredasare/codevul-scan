static void vp8_init_ctx(vpx_codec_ctx_t *ctx)
{
    vpx_codec_alg_priv_t *priv = NULL;

    priv = vpx_calloc(1, sizeof(*priv));
    if (!priv) {
        return;
    }

    ctx->priv = (vpx_codec_priv_t *)priv;
    ctx->priv->init_flags = ctx->init_flags;

    priv->si.sz = sizeof(priv->si);
    priv->decrypt_cb = NULL;
    priv->decrypt_state = NULL;

    if (ctx->config.dec) {
        /* Update the reference to the config structure to an internal copy. */
        priv->cfg = *ctx->config.dec;
        ctx->config.dec = &priv->cfg;
    }
}