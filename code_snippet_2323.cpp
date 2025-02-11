void EVP_DecodeInit(EVP_ENCODE_CTX *ctx)
{
    if (ctx != NULL)
    {
        ctx->num = 0;
        ctx->length = 0;
        ctx->line_num = 0;
        ctx->expect_nl = 0;
    }
    else
    {
        // Log error or throw exception
        // Return error code or exit program
    }
}