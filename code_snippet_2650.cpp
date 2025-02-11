static void vp8_init_ctx(vpx_codec_ctx_t *ctx)
{
    vpx_codec_alg_priv_t *priv =
        (vpx_codec_alg_priv_t *)vpx_calloc(1, sizeof(*priv));

    ctx->priv = (vpx_codec_priv_t *)priv;
    ctx->priv->init_flags = ctx->init_flags;

    priv->si.sz = sizeof(priv->si);
    priv->decrypt_cb = NULL;
    priv->decrypt_state = NULL;

    if (ctx->config.dec && validate_config(&ctx->config.dec) == 0)
    {
        /* Update the reference to the config structure to an internal copy. */
        priv->cfg = *ctx->config.dec;
        ctx->config.dec = &priv->cfg;
    }
    else
    {
        // Handle invalid input, e.g., log an error, return an error code, etc.
    }
}

// Function to validate the config structure
int validate_config(const vpx_codec_cfg_t *config)
{
    // Perform necessary input validations here
    // Return 0 if valid, or an error code if not
    // Example: check the size of the config structure
    if (sizeof(*config) < SOME_MINIMUM_SIZE) {
        return -1;
    }
    return 0;
}