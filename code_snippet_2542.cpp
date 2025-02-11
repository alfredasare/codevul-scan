void EVP_EncodeFinal(EVP_ENCODE_CTX *ctx, unsigned char *out, int *outl)
{
    unsigned int ret = 0;
    size_t remaining_space = *outl - ctx->num - 1;

    if (ctx->num != 0 && remaining_space > 0) {
        ret = EVP_EncodeBlock(out + ctx->num, ctx->enc_data, ctx->num);
        out[ret + ctx->num] = '\n';
        out[ret + ctx->num + 1] = '\0';
        ctx->num = 0;
        *outl = ret + ctx->num + 1;
    } else {
        // Handle error: output buffer too small
        // ...
    }
}