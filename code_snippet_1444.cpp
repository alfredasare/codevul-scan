// Fix for ecdsa_restart_det_free
static void ecdsa_restart_det_free( mbedtls_ecdsa_restart_det_ctx *ctx )
{
    if( ctx == NULL || ctx->is_initialized == 0 || ctx->is_freed == 1 )
        return;

    mbedtls_hmac_drbg_free( &ctx->rng_ctx );

    ctx->is_initialized = 0;
    ctx->is_freed = 1;
}

// Additions for mbedtls_ecdsa_restart_det_init
void mbedtls_ecdsa_restart_det_init( mbedtls_ecdsa_restart_det_ctx *ctx )
{
    // ...
    ctx->is_initialized = 0;
    ctx->is_freed = 0;
    // ...
}

// Additions for mbedtls_ecdsa_restart_det_setup
int mbedtls_ecdsa_restart_det_setup( mbedtls_ecdsa_restart_det_ctx *ctx,
                                     mbedtls_entropy_context *entropy,
                                     mbedtls_ctr_drbg_context *ctr_drbg )
{
    // ...
    ctx->is_initialized = 1;
    ctx->is_freed = 0;
    // ...
}