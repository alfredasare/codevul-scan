int EVP_CipherFinal_ex(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl)
{
    if (!ctx->encrypt && EVP_CIPHER_mode_flags(ctx->cipher, EVP_CIPH_DECrypt)) {
        /* Handle the error appropriately, e.g., return an error code, log an error message, etc. */
        return -1;
    }

    if (ctx->encrypt)
        return EVP_EncryptFinal_ex(ctx, out, outl);
    else
        return EVP_DecryptFinal_ex(ctx, out, outl);
}